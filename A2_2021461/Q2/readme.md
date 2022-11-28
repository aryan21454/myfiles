Firstly we need to add the syscall in syscall table (syscall_64.tbl)
here we have to add the line after the 450
451 common kernel_2d_memcpy sys_kernel_2d_memcpy

And in the sys.c we cedit it and need to add the 
another syscall which is defined by this::
SYSCALL_DEFINE4(kernel_2d_memcpy,float *,arr1,float *,arr2,int,n,int,m)
sys.c located at the /new_kernel/linux-5.19.9/kernel/sys.c
 
In the SYSCALL_DEFINE4 i have used the copy_from_user and the copy_to_user function to copy the data of the matrix or array.
the above funtions takes three arguements the array and new array adderss and the size of the new array.
BUILDING/Compiling the syscall
by using the command

SUFFIX="ashu"

set -e

make -j2

make modules_install

cp arch/x86_64/boot/bzImage /boot/vmlinuz-linux$SUFFIX

sed s/linux/linux$SUFFIX/g \
    </etc/mkinitcpio.d/linux.preset \
    >/etc/mkinitcpio.d/linux$SUFFIX.preset
mkinitcpio -p linux$SUFFIX

grub-mkconfig -o /boot/grub/grub.cfg