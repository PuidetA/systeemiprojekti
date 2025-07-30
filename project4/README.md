# Project 4: Kernel Hacking
Made by:
Arlis Arto Puidet
Miikka Kristian Niinikoski
Date: 2025-07-30


# Instructions on how to get the program running


- [Project 4: Kernel Hacking](#project-4-kernel-hacking)
- [Instructions on how to get the program running](#instructions-on-how-to-get-the-program-running)
- [1. Summary of the steps](#1-summary-of-the-steps)
- [2. Detailed instructions on how to run it](#2-detailed-instructions-on-how-to-run-it)
  - [2.1. Get git and update everything (if you already haven't)](#21-get-git-and-update-everything-if-you-already-havent)
  - [2.2. Install the prerequisites.](#22-install-the-prerequisites)
  - [2.3. Clone xv6-riscv and compile it.](#23-clone-xv6-riscv-and-compile-it)
  - [2.3. Replace the files with modified ones.](#23-replace-the-files-with-modified-ones)
  - [2.4. Run the program itself](#24-run-the-program-itself)
- [3. How to use.](#3-how-to-use)
- [4. What we did.](#4-what-we-did)
- [5. Research details (what we learned)](#5-research-details-what-we-learned)


#   1. Summary of the steps
1. Install/update git
2. Clone xv6-public
3. Make qemu
4. Overwrite with new files
5. Make qemu (again)


# 2. Detailed instructions on how to run it
> [!NOTE]
> The assumption is that this will be run on a fresh Ubuntu machine, so this will go through also the steps on how to set up the environment. This is guaranteed to run on Ubuntu 24.04.2 LTS, but we also got it working on WSL through Windows.

> [!TIP]
> You don't need to clone riscv, and can just 'make qemu' inside the modified folder directly, but this here the most thorough way since that's how we got the results from the tests.

## 2.1. Get git and update everything (if you already haven't)
```bash
# Update package lists and install git
sudo apt-get update && \
sudo apt-get upgrade && \
sudo apt-get install git

```

## 2.2. Install the prerequisites.

```bash
sudo apt-get install autoconf automake autotools-dev curl python3 python3-pip python3-tomli libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev ninja-build git cmake libglib2.0-dev libslirp-dev && \
sudo apt install qemu-system-misc gcc-riscv64-linux-gnu git

```

## 2.3. Clone xv6-riscv and compile it.
> [!NOTE]
> Due to no instructions on which xv6 to install, we decided to use xv6-riscv because xv6-public is no longer supported and they moved the project onto xv6-riscv, which isn't there to add any additional features but improve readability and comprehension according to xv6-public's git page https://github.com/mit-pdos/xv6-public.git
```bash
git clone https://github.com/mit-pdos/xv6-riscv.git && \
cd xv6-riscv
```
> [!WARNING]
> Do not "make qemu" it yet. We will need to do the rest of the steps first.


> [!NOTE]
> To exit xv6-riscv with qemu press "CTRL-A", then let go and press "X".

## 2.3. Replace the files with modified ones.
Now, quit out using CTRL-A X. Then place all the modified files into your directory. (overwrite when prompted)


## 2.4. Run the program itself
And finally, run the program while being inside the xv6-riscv folder.
```bash
make qemu
```

# 3. How to use.
When inside, you should be able to:
1. Run any of the following commands:
```sh
$ getreadcount    # show read count
$ getreadcount 1  # reset
$ getreadcount 2  # enable
$ getreadcount 3  # disable
```
You can also run test_readcount to run an automated test.
```sh
$ test_readcount  # automated test for getreadcount function
```
# 4. What we did.
We modified:
1. kernel/syscall.c
   1. We added getreadcount to syscalls list and made 2 global variables that are used for it.
2. kernel/syscall.h
   1. Assign our new syscall a number (for us, we had 21 syscalls defined, so we made it 22)
3. kernel/sysfile.c
   1. We modified sys_read to use the counter.
4. kernel/sysproc.c
   1. We made sys_getreadcount(void) function
5. user/user.h
   1. Add the function to the list as int getreadcount(int option);
6. user/usys.pl
   1. Added entry
7. Makefile
   1. Added functions to UPROGS
8. user/getreadcount.c
   1. Made the function itself.
9. user/test_readcount.c
   1.  Made an example automated test that the user can run if they don't want to manually check everything.



# 5. Research details (what we learned)
This section will go over everything extra we used to gain an understanding, since it's not all code. And no text references it.

All articles accessed 2025-07-23. This is a bibliography and a recording of our learning journey, so we could potentially go back and re-read things for better clarity.
1. We learned about the file structure from: Stackoverflow (2016), how do i add a system call / utility in xv6. Available at: https://stackoverflow.com/a/13205101/18868434 (Accessed: 30 July 2025)

2. We learned about how to build and set up from: Tofigh, M. (2024) Add the getreadcount system call to XV6, Medium. Available at: https://manitofigh.medium.com/add-the-getreadcount-system-call-to-xv6-820db597f4c5 (Accessed: 30 July 2025). 

3. We used the lecture material and OS-book referenced in Moodle to learn about traps, syscalls, and how it all works under the hood.
