
#include "Matrix3x3.h"
#include <cassert>
#include <cmath>
#include <limits>
#include <sstream>

// 1. Matrix Equivalence
bool Matrix3x3::operator==(const Matrix3x3& aOther) const noexcept {
    return (*this)[0] == aOther[0] &&
        (*this)[1] == aOther[1] &&
        (*this)[2] == aOther[2];
}

// 2. Matrix Multiplication (Matrix * Matrix)
Matrix3x3 Matrix3x3::operator*(const Matrix3x3& aOther) const noexcept {
    const Matrix3x3& M = *this;

    Vector3D col0 = aOther.column(0);
    Vector3D col1 = aOther.column(1);
    Vector3D col2 = aOther.column(2);

    Vector3D row0(M[0].dot(col0), M[0].dot(col1), M[0].dot(col2));
    Vector3D row1(M[1].dot(col0), M[1].dot(col1), M[1].dot(col2));
    Vector3D row2(M[2].dot(col0), M[2].dot(col1), M[2].dot(col2));

    return Matrix3x3(row0, row1, row2);
}

// 3. Transpose
Matrix3x3 Matrix3x3::transpose() const noexcept {
    const Matrix3x3& M = *this;
    return Matrix3x3(M.column(0), M.column(1), M.column(2));
}

// 4. Determinant
float Matrix3x3::det() const noexcept {
    const Matrix3x3& M = *this;
    float a = M[0][0], b = M[0][1], c = M[0][2];
    float d = M[1][0], e = M[1][1], f = M[1][2];
    float g = M[2][0], h = M[2][1], i = M[2][2];

    return a * (e * i - f * h)
        - b * (d * i - f * g)
        + c * (d * h - e * g);
}

// 5. hasInverse
bool Matrix3x3::hasInverse() const noexcept {
    return std::fabs(this->det()) > std::numeric_limits<float>::epsilon();
}

// 6. inverse
Matrix3x3 Matrix3x3::inverse() const noexcept {
    const Matrix3x3& M = *this;
    float detM = M.det();
    assert(std::fabs(detM) > std::numeric_limits<float>::epsilon());

    float a = M[0][0], b = M[0][1], c = M[0][2];
    float d = M[1][0], e = M[1][1], f = M[1][2];
    float g = M[2][0], h = M[2][1], i = M[2][2];

    float invDet = 1.0f / detM;

    Vector3D row0((e * i - f * h) * invDet,
        (c * h - b * i) * invDet,
        (b * f - c * e) * invDet);

    Vector3D row1((f * g - d * i) * invDet,
        (a * i - c * g) * invDet,
        (c * d - a * f) * invDet);

    Vector3D row2((d * h - e * g) * invDet,
        (b * g - a * h) * invDet,
        (a * e - b * d) * invDet);

    return Matrix3x3(row0, row1, row2);
}

// 7. Output operator
std::ostream& operator<<(std::ostream& aOStream, const Matrix3x3& aMatrix) {
    return aOStream << aMatrix[0].toString() << "\n"
        << aMatrix[1].toString() << "\n"
        << aMatrix[2].toString();
}
