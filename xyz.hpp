/// \file xyz.hpp
/// \copyright (c) 2022 ywx9.com

#pragma once

#include "cfenv" ///////////////////////////////////////////////////////////////////////////////////////////////////////
namespace yw {

}

#include "cerrno" //////////////////////////////////////////////////////////////////////////////////////////////////////
namespace yw {

export struct t_std_errno {
  operator int() const noexcept { return yw::_::_errno(); }
  static constexpr int eperm = 1; // operation not permitted
  static constexpr int enoent = 2; // no such file or directory
  static constexpr int esrch = 3; // no such process
  static constexpr int eintr = 4; // interrupted system call
  static constexpr int eio = 5; // I/O error
  static constexpr int enxio = 6; // no such device or address
  static constexpr int e2big = 7; // argument list too long
  static constexpr int enoexec = 8; // exec format error
  static constexpr int ebadf = 9; // bad file number
  static constexpr int echild = 10; // no child processes
  static constexpr int eagain = 11; // try again
  static constexpr int enomem = 12; // out of memory
  static constexpr int eacces = 13; // permission denied
  static constexpr int efault = 14; // bad address
  static constexpr int ebusy = 16; // device or resource busy
  static constexpr int eexist = 17; // file exists
  static constexpr int exdev = 18; // cross-device link
  static constexpr int enodev = 19; // no such device
  static constexpr int enotdir = 20; // not a directory
  static constexpr int eisdir = 21; // illegal operation on a directory
  static constexpr int einval = 22; // invalid argument
  static constexpr int enfile = 23; // file table overflow
  static constexpr int emfile = 24; // too many open files
  static constexpr int enotty = 25; // not a typewriter
  static constexpr int efbig = 27; // file too large
  static constexpr int enospc = 28; // no space left on device
  static constexpr int espipe = 29; // illegal seek
  static constexpr int erofs = 30; // read-only file system
  static constexpr int emlink = 31; // too many links
  static constexpr int epipe = 32; // broken pipe
  static constexpr int edom = 33; // math argument out of domain of func
  static constexpr int erange = 34; // math result not representable
  static constexpr int edeadlk = 36; // resource deadlock would occur
  static constexpr int enametoolong = 38; // file name too long
  static constexpr int enolck = 39; // no record locks available
  static constexpr int enosys = 40; // function not implemented
  static constexpr int enotempty = 41; // directory not empty
  static constexpr int eilseq = 42; // illegal byte sequence
  static constexpr int struncate = 80;
  static constexpr int eaddriinuse = 100; // address already in use
  static constexpr int eaddrnotavail = 101; // address not available
  static constexpr int eafnosupport = 102; // address family not supported
  static constexpr int ealready = 103; // connection already in progress
  static constexpr int ebadmsg = 104; // bad message
  static constexpr int ecanceled = 105; // operation canceled
  static constexpr int econnaborted = 106; // connection aborted
  static constexpr int econnrefused = 107; // connection refused
  static constexpr int econnreset = 108; // connection reset
  static constexpr int edestaddrreq = 109; // destination address required
  static constexpr int ehostunreach = 110; // host is unreachable
  static constexpr int eidrm = 111; // identifier removed
  static constexpr int einprogress = 112; // operation in progress
  static constexpr int eisconn = 113; // socket is connected
  static constexpr int eloop = 114; // too many levels of symbolic links
  static constexpr int emsgsize = 115; // message too long
  static constexpr int enetdown = 116; // network is down
  static constexpr int enetreset = 117; // network dropped connection on reset
  static constexpr int enetunreach = 118; // network is unreachable
  static constexpr int enobufs = 119; // no buffer space available
  static constexpr int enodata = 120; // no message is available on the STREAM head read queue
  static constexpr int enolink = 121; // link has been severed
  static constexpr int enomsg = 122; // no message of the desired type
  static constexpr int enoprotoopt = 123; // protocol not available
  static constexpr int enosr = 124; // no STREAM resources
  static constexpr int enostr = 125; // stream ioctl() error
  static constexpr int enotconn = 126; // socket is not connected
  static constexpr int enotrecoverable = 127; // state not recoverable
  static constexpr int enotsock = 128; // socket operation on non-socket
  static constexpr int enotsup = 129; // operation not supported on socket
  static constexpr int eopnotsupp = 130; // operation not supported on socket
  static constexpr int eother = 131; // some other error
  static constexpr int eoverflow = 132; // value too large to be stored in data type
  static constexpr int eownerdead = 133; // previous owner died
  static constexpr int eproto = 134; // protocol error
  static constexpr int eprotonosupport = 135; // protocol not supported
  static constexpr int eprototype = 136; // protocol wrong type for socket
  static constexpr int etime = 137; // stream ioctl() timeout
  static constexpr int etimedout = 138; // connection timed out
  static constexpr int etxtbsy = 139; // text file busy
  static constexpr int ewouldblock = 140; // operation would block
};

/// alternative for `errno` macro
export inline constexpr t_std_errno std_errno;
}
