#include "is_symmetric.h"

template <typename T>
IGL_INLINE bool igl::is_symmetric(const Eigen::SparseMatrix<T>& A)
{
  if(A.rows() != A.cols())
  {
    return false;
  }
  Eigen::SparseMatrix<T> AT = A.transpose();
  Eigen::SparseMatrix<T> AmAT = A-AT;
  //// Eigen screws up something with LLT if you try to do
  //SparseMatrix<T> AmAT = A-A.transpose();
  //// Eigen crashes at runtime if you try to do
  // return (A-A.transpose()).nonZeros() == 0;
  return AmAT.nonZeros() == 0;
}

#ifndef IGL_HEADER_ONLY
// Explicit template specialization
#endif