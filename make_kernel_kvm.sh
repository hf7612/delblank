set -x
pushd /home/user/linux_git.
n make bzImage -j32
scp bzImage  h@h:/boot/vmlinuz-3.16.0+
popd