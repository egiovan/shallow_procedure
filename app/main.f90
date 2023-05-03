program main
  use shallow_procedure, only: shallow_transpose
  implicit none

  integer,target :: a(3,4)
  integer, pointer :: ap(:,:)
  integer :: i, status
  a = reshape([(i,i=1,size(a))], shape(a))

  call shallow_transpose(a, ap, status)
  print *, 'Status:', status
  call printp(a,'The original')
  call printp(ap,'The transposed')

contains
subroutine printp(v, message)
  integer, intent(in) :: v(:,:)
  character(len=*),intent(in) :: message
  integer :: i,k

  print *, message
  do i=1, size(v, 1)
    print "(*(x, I4))",(v(i,k), k=1, size(v,2))
  enddo
end subroutine
end program main
