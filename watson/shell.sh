########## Linux Command ############
date
cal
pwd
cd
    cd # home
    cd - # previous dir
    cd ~username # user home dir

ls
    ls -la
    ls --color=auto

file filename # determine file's type
less
cp
    cp -u src dst # copy only when the SOURCE file is newer than the destination file or when the destination file is missing
    cp -i src dst # user is prompted when dst does exist
    cp -r src dst # recursive

mkdir
    mkdir -p dir/dir # recursive

mv
    mv -i # user is prompted when dst does exist, otherwise overwrite file

rm
    rm -i
    rm -r
    rm -f
    rm -v

ln
    ln -s #symbolic links

# Working with CMD
type command # see how it executed
which command # display an executable's location
man command
apropos command # display appropriate commands 
whatis command # display a very brief description of a command
info command # display a program's info entry
whereis command # 
alias
unalias

# Redirection
> # redirect to file
>> # append redirected output
2> # redirect stderr
&> # redirect stdout and stderr
> file 2>@1 # same as &>
cat
    cat src >/>> dst 
    cat > dst

| # pipeline
    output | sort | uniq | less # omit repeated lines
    output | sort | uniq -d | less # only see duplicates
 
wc
    wc -l # line
    wc -w # words
    wc -c # char

grep
    
head -n 5 file # see frst 5 lines
tail
    tail -n 5 file # see last 5 lines
    tail -f # monitor the file
tee # read from stdin and output to stdout and file

# Double Quotes
ls -l "can have space" 
echo "this is a    test"
echo this is a    test
echo $(cal)
echo "$(cal)"

# Single Quotes
echo text ~/*.txt {a,b} $(echo foo) $((2+ 4)) $USER
echo "text ~/*.txt {a,b} $(echo foo) $((2+ 4)) $USER"
echo 'text ~/*.txt {a,b} $(echo foo) $((2+ 4)) $USER' # suppress all expansions

# Escaping char
\$
\\

# Permissions
id
umask # set default permissions
chmod
chown
    chown bob
    chown bob:users
    chown :admins
    chown bob:

chgrp
passwd

# Processes
ps
    ps x # display all processes
    ps aux # more info, a + u + x

top
jobs
bg
fg  # ^z will detach it
kill
killall
shutdown
pstree
vmstat

# Environment
printenv
set # set shell option
export
alias
echo $SHELL $EDITOR $DISPLAY $HOME $LANG $OLD_PWD $PAGER $PATH $PS1 $PWD $TERM $TZ $USER

# Package Management
# .deb -> Debian style   dpkg, apt-get, aptitude          Debian, Ubuntu, Xandros, Linspire
# .rpm -> Red Hat style  rpm, yum                         Fedora, CentOS, Red Hat Enterprise, openSUSE, Mandriva, PCLinuxOS
apt-get update
apt-cache search search_string
apt-get install
yum search search_string

dpkg --install pkg_file
rpm -i pkg_file
rpm -U pkg_file

apt-get remove pkg_name
yum erase pkg_name

dpkg --list # list installed pkg
rpm -qa

dpkg --status pkg_name # determining if a pkg is installed
rpm -q pkg_name

apt-cache show pkg_name # displaying info about an installed pkg
yum info pkg_name

dpkg --search file_name # finding which pkg installed a file
rpm -qf file_name

# Storage
mount
umount
fdisk # partition table manipulator
fsck # check and repare a file system
mkfs # create a file system
md5sum # calculate MD5 checksum

# Networking
ping
traceroute
netstat
    netstat -r # display the kernel's network routing table

ftp
    ftp fileserver
        anonymous
        cd # file server dir
        lcd # local dir
        get filename 
        bye

lftp # a better ftp
wget
ssh
    ssh remote-host free
    ssh remote-host 'ls *' > dirlist.txt # in local
    ssh remote-host 'ls * > dirlist.txt' # in remote

scp
sftp
    sftp remote-host
        ls
        cd
        lcd
        get filename
        bye

# Searching for files
locate # find file by name
    locate bin/zip

find # search for files in a directory hierarchy
    find ~ -type d/f/l/c/b | wc -l
    find ~ -type f -name "*.jpg" -size +1M | wc -l
    find ~ \( -type f -not -perm 0600 \) -or \( -type d -not -perm 0700 \) # -and, -or, -not
    find ~ -type f -name '*.BAK' -delete
    find ~ -type f -name 'foo*' -ok ls -l '{}' ';' # using the -ok action prompts user before the ls command is executed
    find ~ -type f -name 'foo*' -exec ls -l '{}' ';' # -exec launches a new instance of the specified command each time a matching file is found
    find ~ -type f -name 'foo*' -exec ls -l '{}' '+' # execute ls command only once
    find ~ -type f -name 'foo*' -print | xargs ls -l

xargs # build and execute command lines from standard input
touch # change file times
stat # display file or file system status

# Archiving and Backup
gzip # compress or expand files
    gzip foo.txt
    gzip -tv foo.txt
    gunzip fon.txt

bzip2 # a block sorting file compressor
    bzip2 foo.txt
    bunzip2 foo.txt

tar # tape-archiving utility
    tar cf filename.tar filename/pathname
    tar tvf filename.tar # test
    tar xf  filename.tar pathname

zip # package and compress files
    zip -r filename.zip dir
    unzip finename.zip

rsync # remote file and directory synchronization

# Text processing
cat
    cat -ns file

sort
    sort src1 src2 src3 > dst

uniq
cut # remove sections from each line of file
paste # merge lines of files
join # join lines of two files on a common field
comm # compare two sorted files line by line
diff
patch # apply a diff file to an original
tr # translate or delete char
    echo "aaabbbccc" | tr -s ab # squeeze

sed # stream editor for filtering and transforming text
    echo "front" | sed 's/front/back/'
    echo "front" | sed 's_front_back_'
    echo "aaabbbccc" | sed 's/b/B/'
    echo "aaabbbccc" | sed 's/b/B/g'
aspell # interactive spell checker

# Formatting output
nl # number lines
fold # wrap each line to a specified lengh
fmt # a simple text formatter
pr # format text for printing
printf # format and print data
groff # a document formatting system

# Others
echo # display a line of text
    echo $((2 + 4))
    echo $((expression)) # arithmetic expansion
    echo Number_{1..5}
    echo a{A{1,2},B{3,4}}b # aA1b aA2b aB3b aB4b
    echo $USER
    echo $(ls)

df
free
ctrl-alt-f1~f6, f7 is gui
xinput --set-prop "SynPS/2 Synaptics TouchPad" "Device Enabled" 0

