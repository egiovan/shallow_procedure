# shallow_procedure

Thi module implement a `shallow_transpose` procedure defined as:

```fortran
subroutine shallow_transpose(src, dst, status)
  f_type, intent(in), pointer :: src(:,:)
  f_type, intent(out), pointer :: dst(:,:)
  integer, intent(out) :: status
```
Equivalent, if it were possible, to:
```fortran
dst => transpose(src)
```
The last syntax is obviously rejected by the compilers as the result of a function has not, in general, the pointer attribute.
It should be said that due to the restriction on the modification of the descriptor the routine `shallow_transpose` it's still not conformant to the Fortran Standard.

Take it with care and just as a didactic exercise.
Don't use in any software except in didactic one.
