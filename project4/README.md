### Instructions on how to get the program running


- [0. Table of contents](#0-table-of-contents)
- [1. Summary of the steps](#1-summary-of-the-steps)
- [2. Detailed instructions on how to run it](#2-detailed-instructions-on-how-to-run-it)
  - [2.1. Get git and clone xv6-public](#21-get-git-and-clone-xv6-public)
  - [2.2. Run the patch](#22-run-the-patch)
  - [2.3. Run the program itself](#23-run-the-program-itself)
- [3. Research details (what we learned)](#3-research-details-what-we-learned)





#   0. Table of contents
1. Summary of the steps
2. Detailed instructions on how to run it
3. Research details (what we learned)


#   1. Summary of the steps
1. Install/update git
2. Clone xv6-public
3. Apply our patches
4. Make qemu


# 2. Detailed instructions on how to run it
> [!NOTE]
> The assumption is that this will be run on a fresh machine, so this will go through the steps also on how to set up the environment
## 2.1. Get git and clone xv6-public
```bash
# Update package lists and install git
sudo apt-get update && \
sudo apt-get install git
```
## 2.2. Run the patch

## 2.3. Run the program itself





# 3. Research details (what we learned)
This section will go over everything extra we used to gain an understanding, since it's not all code. And no text references it.

All articles accessed 2025-07-23. This is a bibliography and a recording of our learning journey, so we could potentially go back and re-read things for better clarity.
1. We learned about the file structure from: https://stackoverflow.com/questions/8021774/how-do-i-add-a-system-call-utility-in-xv6?rq=1

2. We learned about how to build and set up from: https://manitofigh.medium.com/add-the-getreadcount-system-call-to-xv6-820db597f4c5

3. We used the lecture material and OS-book referenced in Moodle to learn about traps, syscalls, and how it all works under the hood.

4. 
