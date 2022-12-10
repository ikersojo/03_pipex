# 03_PIPEX
In this project the behaviour of UNIX **pipe ( | )** will be replicated.

# Scope of the Mandatory part:
The program shall replicate the output of the shell command:
```
< file1 cmd1 | cmd2 > file2
```

with the following sytanx:
```
./pipex file1 cmd1 cmd2 file2
```

## Program layout and instruction sequence:
The Program is divided in the following key functions:
- ft_pipex.c:
	- main function:
		- checks the input arguments
		- opens infile and out file
		- launches the loop of the commands specified in arguments
		- directly runs the last command to be placed in outfile

	- run process function:
		- creates a pipe and a fork
		- for the father:
			- closes the write end of the pipe
			- clones the stdin input to the read end of the pipe
			- waits for the children
		- for the children:
			- closes the read end of the pipe
			- clones the stdout to the write end of the pipe, for the father to read.
			- runs the requested command (see utils)

- ft_pipex_utils.c:
	- run command:
		- works with the string provided in each argument to create a cmd string array, emulating argv. It does consider double quotation in the input
		- locates the path of the command to run (arg[0]) from the environment PATH variable
		- executes the command's binary
		- frees all memory used to do the above

	- error handling: using perror provides information on any error during execution.

- libft: All additional smaller functions to make things work (ft_split, ft_strjoin, ft_putstr_fd...).

# Scope of the Bonus part:
...

# SCORE
TBD...



# APPENDIX
## New allowed functions:
- access:
```
#include <unistd.h>
int  access(const char *path, int mode);

The access() system call checks the accessibility of the file named by the
current user, considering the follwoing mode:
- R_OK checks for read permission.
- W_OK checks for write permission.
- X_OK checks for execute permission.
- F_OK checks if the file exists.
```

- open:
```
#include <fcntl.h>
int  open(const char *path, int oflag, ...);

The file name specified by path is opened for reading and/or writing,
as specified by the argument oflag; the file descriptor is returned to
the calling process.

The flags specified for the oflag argument must include exactly one of
the following file access modes:

	O_RDONLY        open for reading only
	O_WRONLY        open for writing only
	O_RDWR          open for reading and writing

In addition any combination of the following values can be included using pipe
symbol:

	O_NONBLOCK      do not block on open or for data to become available
	O_APPEND        append on each write
	O_CREAT         create file if it does not exist
	O_TRUNC         truncate size to 0
	O_EXCL          error if O_CREAT and the file exists
	O_SHLOCK        atomically obtain a shared lock
	O_EXLOCK        atomically obtain an exclusive lock
	O_DIRECTORY     restrict open to a directory
	O_NOFOLLOW      do not follow symlinks
	O_SYMLINK       allow open of symlinks
	O_EVTONLY       descriptor requested for event notifications only
	O_CLOEXEC       mark as close-on-exec
	O_NOFOLLOW_ANY  do not follow symlinks in the entire path.
```

- unlink:
```
#include <unistd.h>
int  unlink(const char *path);

The unlink() function removes the link named by path from its directory and
decrements the link count of the file which was referenced by the link. If
that decrement reduces the link count of the file to zero, and no process
has the file open, then all resources associated with the file are reclaimed.
If one or more process have the file open when the last link is removed, the
link is removed, but the removal of the file is delayed until all references
to it have been closed.

Upon successful completion, a value of 0 is returned.  Otherwise, a value of -1
is returned and errno is set to indicate the error.
```

- close:
```
#include <unistd.h>
int  close(int fildes);

The close() call deletes a descriptor from the per-process object reference
table.

Upon successful completion, a value of 0 is returned.  Otherwise, a value of -1
is returned and errno is set to indicate the error.
```

- read:
```
#include <unistd.h>
ssize_t  read(int fildes, void *buf, size_t nbyte);

read() attempts to read nbyte bytes of data from the object referenced by the
descriptor fildes into the buffer pointed to by buf.

If successful, the number of bytes actually read is returned. Upon reading EoF,
zero is returned. Otherwise, a -1 is returned and the global variable errno is
set to indicate the error.
```

- waitp and waitpid:
```
#include <sys/wait.h>
pid_t  wait(int *stat_loc);
pid_t  waitpid(pid_t pid, int *stat_loc, int options);

The wait() function suspends execution of its calling process until
stat_loc information is available for a terminated child process, or a
signal is received. On return from a successful wait() call, the
stat_loc area contains termination information about the process that
exited as defined below.

The pid parameter specifies the set of child processes for which to wait:
If pid is -1, the call waits for any child process.
If pid is 0, the call waits for any child process in the process group of the caller.
If pid is greater than zero, the call waits for the process with process id pid.
If pid is less than -1, the call waits for any process whose process group id
equals the absolute value of pid.

The waitpid() call provides a more general interface for programs that
need to wait for certain child processes, that need resource
utilization statistics accumulated by child processes, or that require
options.

The following macros may be used to test the manner of exit of the
process. One of the first three macros will evaluate to a non-zero
(true) value:

	WIFEXITED(status)
		True if the process terminated normally by a call to _exit(2)
		or exit(3).

	WIFSIGNALED(status)
		True if the process terminated due to receipt of a signal.

	WIFSTOPPED(status)
		True if the process has not terminated, but has stopped and
		can be restarted.  This macro can be true only if the wait
		call specified the WUNTRACED option or if the child process is
		being traced (see ptrace(2)).

Depending on the values of those macros, the following macros produce
the remaining status information about the child process:

	WEXITSTATUS(status)
		If WIFEXITED(status) is true, evaluates to the low-order 8
		bits of the argument passed to _exit(2) or exit(3) by the
		child.

	WTERMSIG(status)
		If WIFSIGNALED(status) is true, evaluates to the number of the
		signal that caused the termination of the process.

	WCOREDUMP(status)
		If WIFSIGNALED(status) is true, evaluates as true if the
		termination of the process was accompanied by the creation of
		a core file containing an image of the process when the signal
		was received.

	WSTOPSIG(status)
		If WIFSTOPPED(status) is true, evaluates to the number of the
		signal that caused the process to stop.

```

- pipe:
```
#include <unistd.h>
int  pipe(int fildes[2]);

The pipe() function creates a pipe (an object that allows unidirectional data
flow) and allocates a pair of file descriptors. The first descriptor connects
to the read end of the pipe; the second connects to the write end.

Data written to fildes[1] can be read from fildes[0]. This allows the output of
one program to be sent to another program. The pipe itself persists until all
of its associated descriptors are closed.

A pipe whose read or write end has been closed is considered widowed. Widowing
a pipe is the only way to deliver EoF to a reader: after the reader consumes
any buffered data, reading a widowed pipe returns a zero count.

On successful creation of the pipe, zero is returned. Otherwise, a value of -1
is returned and the variable errno set to indicate theerror.
```

- dup and dup2:
```
#include <unistd.h>
int  dup(int fildes);
int  dup2(int fildes, int fildes2);

dup() duplicates an existing object descriptor and returns its value
to the calling process (fildes2 = dup(fildes)).  The argument fildes
is a small non-negative integer index in the per-process descriptor
table.  The value must be less than the size of the table, which is
returned by getdtablesize(2).  The new descriptor returned by the call
is the lowest numbered descriptor currently not in use by the process.

The object referenced by the descriptor does not distinguish between
fildes and fildes2 in any way.  Thus if fildes2 and fildes are
duplicate references to an open file, read(2), write(2) and lseek(2)
calls all move a single pointer into the file, and append mode, non-
blocking I/O and asynchronous I/O options are shared between the
references.  If a separate pointer into the file is desired, a
different object reference to the file must be obtained by issuing an
additional open(2) call.  The close-on-exec flag on the new file
descriptor is unset.

In dup2(), the value of the new descriptor fildes2 is specified.  If
fildes and fildes2 are equal, then dup2() just returns fildes2; no
other changes are made to the existing descriptor.  Otherwise, if
descriptor fildes2 is already in use, it is first deallocated as if a
close(2) call had been done first.

Upon successful completion, the new file descriptor is returned.
Otherwise, a value of -1 is returned and the global integer variable
errno is set to indicate the error.
```

- execve:
```
#include <unistd.h>
int  execve(const char *path, char *const argv[], char *const envp[]);

execve() transforms the calling process into a new process.  The new
process is constructed from an ordinary file, whose name is pointed to
by path, called the new process file.  This file is either an
executable object file, or a file of data for an interpreter.  An
executable object file consists of an identifying header, followed by
pages of data representing the initial program (text) and initialized
data pages.  Additional pages may be specified by the header to be
initialized with zero data;  see a.out(5).

The argument argv is a pointer to a null-terminated array of character
pointers to null-terminated character strings.  These strings
construct the argument list to be made available to the new process.
At least one argument must be present in the array; by custom, the
first element should be the name of the executed program (for example,
the last component of path).

The argument envp is also a pointer to a null-terminated array of
character pointers to null-terminated strings.  A pointer to this
array is normally stored in the global variable environ. These strings
pass information to the new process that is not directly an argument
to the command (see environ(7)).

File descriptors open in the calling process image remain open in the
new process image, except for those for which the close-on-exec flag
is set (see close(2) and fcntl(2)).  Descriptors that remain open are
unaffected by execve().

As the execve() function overlays the current process image  with a
new process image, the successful call has no process to return to.
If execve() does return to the calling process, an error has occurred;
the return value will be -1 and the global variable errno is set to
indicate the error.
```

- fork:
```
#include <unistd.h>
pid_t  fork(void);

fork() causes creation of a new process.  The new process (child
process) is an exact copy of the calling process (parent process)
except for the following:

	•   The child process has a unique process ID.

	•   The child process has a different parent process ID (i.e.,
		the process ID of the parent process).

	•   The child process has its own copy of the parent's
		descriptors.  These descriptors reference the same
		underlying objects, so that, for instance, file pointers in
		file objects are shared between the child and the parent, so
		that an lseek(2) on a descriptor in the child process can
		affect a subsequent read or write by the parent.  This
		descriptor copying is also used by the shell to establish
		standard input and output for newly created processes as
		well as to set up pipes.

Upon successful completion, fork() returns a value of 0 to the child
process and returns the process ID of the child process to the parent
process.  Otherwise, a value of -1 is returned to the parent process,
no child process is created, and the global variable errno is set to
indicate the error.
```

- perror:
```
#include <stdio.h>
void  perror(const char *s);

The perror() function finds the error message corresponding to the
current value of the global variable errno (intro(2)) and writes it,
followed by a newline, to the standard error file descriptor.  If the
argument s is non-NULL and does not point to the null character, this
string is prepended to the message string and separated from it by a
colon and space (“: ”); otherwise, only the error message string is
printed.
```

- strerror:
```
#include <string.h>
char  *strerror(int errnum);

The strerror() function accepts an error number argument errnum and
returns a pointer to the corresponding message string.
```

- exit:
```
#include <stdlib.h>
void  exit(int status);

The exit() function terminates a process.

Before termination, exit() performs the following functions in the
order listed:

	1.   Call the functions registered with the atexit(3) function,
		in the reverse order of their registration.

	2.   Flush all open output streams.

	3.   Close all open streams.

	4.   Unlink all files created with the tmpfile(3) function.

The C Standard (ISO/IEC 9899:1999 (“ISO C99”)) defines the values 0,
EXIT_SUCCESS, and EXIT_FAILURE as possible values of status.
```
