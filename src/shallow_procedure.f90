module shallow_procedure
  implicit none

  !void shallow_transpose(CFI_cdesc_t *src, CFI_cdesc_t *dst, int *status)
  interface shallow_transpose
  
  subroutine shallow_transpose_i32_2(src, dst, status) bind(C,name="shallow_transpose")
    use iso_c_binding
    integer(C_INT),pointer,intent(in) :: src(:,:)
    integer(C_INT),pointer,intent(out) :: dst(:,:)
    integer(C_INT),intent(out) :: status
  end subroutine

  subroutine shallow_transpose_f32_2(src, dst, status) bind(C,name="shallow_transpose")
    use iso_c_binding
    real(C_FLOAT),pointer,intent(in) :: src(:,:)
    real(C_FLOAT),pointer,intent(out) :: dst(:,:)
    integer(C_INT),intent(out) :: status
  end subroutine

  end interface

contains
  
end module shallow_procedure
