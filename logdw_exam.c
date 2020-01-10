// #include <sys/types.h>          /* See NOTES */
//        #include <sys/socket.h>
// #include"linux/un.h"
// 	   // #include <utils/Log.h>
// // #include "log.h"
// // #include <android-base/logging.h>
// // #include <log/log.h>
// // enum LogSeverity2 {
// //   VERBOSE,
// //   DEBUG,
// //   INFO,
// //   WARNING,
// //   ERROR,
// //   FATAL_WITHOUT_ABORT,
// //   FATAL,
// // };
// // git whatchanged origin/master --  cmds/app_process/app_main.cpp
// // system/core/liblog/logd_writer.cpp:static int logdAvailable(log_id_t LogId);
// // logd机制使得每个客户端多建立了一个socket，即使后面不再写log也会维持，是否有点浪费内存
// // frameworks/native/libs/binder/ProcessState.cpp 创建 Binder: 线程  out/target/product/msm8937_32go/system/lib/libbinder.so out/target/product/msm8937_32go/system/lib/vndk-29/libbinder.so        system/vold/VoldNativeService.cpp:sp<ProcessState> ps(ProcessState::self());  system/vold/main.cpp:android::vold::VoldNativeService::start()  system/vold/VoldNativeService.h:class VoldNativeService : public BinderService<VoldNativeService>, public os::BnVold {               service vold /system/bin/vold  --blkid_context=u:r:blkid:s0 --blkid_untrusted_context=u:r:blkid_untrusted:s0  --fsck_context=u:r:fsck:s0 --fsck_untrusted_context=u:r:fsck_untrusted:s0;        用gdbserver和gdbserver64取决于对应的进程是32位还是64位的，可以通过cat /proc/processpid/maps | grep system/lib看link的是lib还是lib64的so确定   out/target/product/msm8937_32go/system/bin/bootstrap/linker与out/target/product/msm8937_32go/system/apex/com.android.runtime.release/bin/linker相同           frameworks/base/services/core/java/com/android/server/StorageManagerService.java:binder = ServiceManager.getService("vold");            a shell gdbserver :5039 /data/l --blkid_context=u:r:blkid:s0 --blkid_untrusted_context=u:r:blkid_untrusted:s0  --fsck_context=u:r:fsck:s0 --fsck_untrusted_context=u:r:fsck_untrusted:s0;            a shell setprop  ro.product.name msm8937_32go; gdbclient.py -p pidx #前面a shell gdbserver打印的pid            Thread 333.333 "Binder:333_2" android::IPCThreadState::talkWithDriver (this=0xb5b36000, doReceive=<optimized out>) at frameworks/native/libs/binder/IPCThreadState.cpp:982          external/jemalloc_new/src/jemalloc.c:2035           recvmsg(18, {msg_name=NULL, msg_namelen=0, msg_iov=[{iov_base="\0B\4LS0\\\256\2131;\4/data/l\0joes local V"..., iov_len=4079}], msg_iovlen=1, msg_control=[{cmsg_len=24, cmsg_level=SOL_SOCKET, cmsg_type=SCM_CREDENTIALS, cmsg_data={pid=1090, uid=0, gid=0}}], msg_controllen=24, msg_flags=0}, 0) = 67               writev(13, [{iov_base="8\0\34\0B\4\0\0B\4\0\0JS0\\\177\5\341:\0\0\0\0\0\0\0\0", iov_len=28}, {iov_base="\4/data/l\0joes local Vold 3.0 (th"..., iov_len=56}], 2) = 84               #include <log/log.h>        socket(AF_UNIX, SOCK_DGRAM|SOCK_CLOEXEC|SOCK_NONBLOCK, 0)=3  connect(3, {sa_family=AF_UNIX, sun_path="/dev/socket/logdw"}, 110) = 0     writev(3, [{iov_base="\0\r\ti\2010\\\324qS.", iov_len=11}, {iov_base="\4", iov_len=1}, {iov_base="/data/local/tmp/l.cpp\0", iov_len=22}, {iov_base="aaaaaaaaaaaaaaaaabbbbbbbbbbbb\0", iov_len=30}], 4) = 64
// int  main(){
// 	int i=0;
// 	i*=8;
// 	if(i>9) i*=9;
// 	// printf(" ffffffffffffffffffffffddddd \n");
// 	// LOG(INFO) << "aaaaaaaaaaaaaaaaabbbbbbbbbbbb"; i++;
// 	// LOG(INFO) << "aaaaaaaaaaaaaaaaabbbbbbbbbbbb2 "<<i;i++;
// 	// LOG(INFO) << "aaaaaaaaaaaaaaaaabbbbbbbbbbbb2 "<<i;i++;
// 	// LOG(INFO) << "aaaaaaaaaaaaaaaaabbbbbbbbbbbb2 "<<i;i++;
// 	// LOG(INFO) << "aaaaaaaaaaaaaaaaabbbbbbbbbbbb2 "<<i;i++;
// 	// LOG(INFO) << "aaaaaaaaaaaaaaaaabbbbbbbbbbbb2 "<<i;i++;
// 	// LOG(INFO) << "aaaaaaaaaaaaaaaaabbbbbbbbbbbb2 "<<i;i++;
// 	int s=socket(AF_UNIX, SOCK_DGRAM|SOCK_CLOEXEC|SOCK_NONBLOCK, 0);
// 	if(s>=0){
// 		struct sockaddr_un addr;//={0};
// 		// struct sockaddr addr={0};
// 		addr.sa_family=AF_UNIX;
// 		// addr.sun_path="/dev/socket/logdw";
// 		strcpy(sockun.sun_path, "/dev/socket/logdw");
// 		int c = connect(s, addr, 110);//{sa_family=AF_UNIX, sun_path="/dev/socket/logdw"}, 110) = 0     writev(3, [{iov_base="\0\r\ti\2010\\\324qS.", iov_len=11}, {iov_base="\4", iov_len=1}, {iov_base="/data/local/tmp/l.cpp\0", iov_len=22},
// 		// {iov_base="aaaaaaaaaaaaaaaaabbbbbbbbbbbb\0", iov_len=30}], 4) =
// 		// if(c>=0){
// 		// 	write()
// 		// }
// 	}
// 	// LOGD(" aaa ");
// 	// while (1)
// 	// {
// 	// 	// sleep(1);
// 	// }
// 	// pause();
// 	return 0;
// }
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <error.h>
#include <android/log.h>
#include <time.h>
#include <sys/uio.h>

#define EINTR 4
// #define TEMP_FAILURE_RETRY
int errno;
#define __close close
struct log_time { uint32_t tv_sec; uint32_t tv_nsec; };
// struct BufferOutputStream {
//  public:
//   BufferOutputStream(char* buffer, size_t size) : total(0), pos_(buffer), avail_(size) {
//     if (avail_ > 0) pos_[0] = '\0'; }
//   ~BufferOutputStream() = default;
//   void Send(const char* data, int len) {
//     if (len < 0) { len = strlen(data); }
//     total += len;
//     if (avail_ <= 1) {       // No space to put anything else.
//       return; }
//     if (static_cast<size_t>(len) >= avail_) { len = avail_ - 1; }
//     memcpy(pos_, data, len); pos_ += len; pos_[0] = '\0'; avail_ -= len; }
//   size_t total;
//  private:
//   char* pos_; size_t avail_; };
// struct FdOutputStream {
//  public:
//   explicit FdOutputStream(int fd) : total(0), fd_(fd) {}
//   void Send(const char* data, int len) { if (len < 0) { len = strlen(data); }
//     total += len;
//     while (len > 0) { ssize_t bytes = TEMP_FAILURE_RETRY(write(fd_, data, len));
//       if (bytes == -1) { return; }
//       data += bytes; len -= bytes; } }
//   size_t total;
//  private:
//   int fd_; };
// static void out_vformat(Out& o, const char* format, va_list args) {
//   int nn = 0;
//   for (;;) {
//     int mm;
//     int padZero = 0;
//     int padLeft = 0;
//     char sign = '\0';
//     int width = -1;
//     int prec = -1;
//     size_t bytelen = sizeof(int);
//     int slen;
//     char buffer[32]; /* temporary buffer used to format numbers */
//     char c;     /* first, find all characters that are not 0 or '%' */     /* then send them to the output directly */
//     mm = nn;
//     do {
//       c = format[mm];
//       if (c == '\0' || c == '%') break;
//       mm++;
//     } while (1);
//     if (mm > nn) {
//       o.Send(format + nn, mm - nn);
//       nn = mm;
//     }     /* is this it ? then exit */
//     if (c == '\0') break;     /* nope, we are at a '%' modifier */
//     nn++;  // skip it     /* parse flags */
//     for (;;) {
//       c = format[nn++];
//       if (c == '\0') { /* single trailing '%' ? */
//         c = '%';
//         o.Send(&c, 1);
//         return;
//       } else if (c == '0') {
//         padZero = 1;
//         continue;
//       } else if (c == '-') {
//         padLeft = 1;
//         continue;
//       } else if (c == ' ' || c == '+') {
//         sign = c;
//         continue;
//       }
//       break;
//     }     /* parse field width */
//     if ((c >= '0' && c <= '9')) {
//       nn--;
//       width = static_cast<int>(parse_decimal(format, &nn));
//       c = format[nn++];
//     }     /* parse precision */
//     if (c == '.') {
//       prec = static_cast<int>(parse_decimal(format, &nn));
//       c = format[nn++];
//     }     /* length modifier */
//     switch (c) {
//       case 'h':
//         bytelen = sizeof(short);
//         if (format[nn] == 'h') {
//           bytelen = sizeof(char);
//           nn += 1;
//         }
//         c = format[nn++];
//         break;
//       case 'l':
//         bytelen = sizeof(long);
//         if (format[nn] == 'l') {
//           bytelen = sizeof(long long);
//           nn += 1;
//         }
//         c = format[nn++];
//         break;
//       case 'z':
//         bytelen = sizeof(size_t);
//         c = format[nn++];
//         break;
//       case 't':
//         bytelen = sizeof(ptrdiff_t);
//         c = format[nn++];
//         break;
//       default:;
//     }     /* conversion specifier */
//     const char* str = buffer;
//     if (c == 's') {       /* string */
//       str = va_arg(args, const char*);
//       if (str == nullptr) {
//         str = "(null)";
//       }
//     } else if (c == 'c') {       /* character */       /* NOTE: char is promoted to int when passed through the stack */
//       buffer[0] = static_cast<char>(va_arg(args, int));
//       buffer[1] = '\0';
//     } else if (c == 'p') {
//       uint64_t value = reinterpret_cast<uintptr_t>(va_arg(args, void*));
//       buffer[0] = '0';
//       buffer[1] = 'x';
//       format_integer(buffer + 2, sizeof(buffer) - 2, value, 'x');
//     } else if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X') {       /* integers - first read value from stack */
//       uint64_t value;
//       int is_signed = (c == 'd' || c == 'i' || c == 'o');       /* NOTE: int8_t and int16_t are promoted to int when passed        *       through the stack        */
//       switch (bytelen) {
//         case 1:
//           value = static_cast<uint8_t>(va_arg(args, int));
//           break;
//         case 2:
//           value = static_cast<uint16_t>(va_arg(args, int));
//           break;
//         case 4:
//           value = va_arg(args, uint32_t);
//           break;
//         case 8:
//           value = va_arg(args, uint64_t);
//           break;
//         default:
//           return; /* should not happen */
//       }       /* sign extension, if needed */
//       if (is_signed) {
//         int shift = 64 - 8 * bytelen;
//         value = static_cast<uint64_t>((static_cast<int64_t>(value << shift)) >> shift);
//       }       /* format the number properly into our buffer */
//       format_integer(buffer, sizeof(buffer), value, c);
//     } else if (c == '%') {
//       buffer[0] = '%';
//       buffer[1] = '\0';
//     } else {
//       __assert(__FILE__, __LINE__, "conversion specifier unsupported");
//     }     /* if we are here, 'str' points to the content that must be      * outputted. handle padding and alignment now */
//     slen = strlen(str);
//     if (sign != '\0' || prec != -1) {
//       __assert(__FILE__, __LINE__, "sign/precision unsupported");
//     }
//     if (slen < width && !padLeft) {
//       char padChar = padZero ? '0' : ' ';
//       SendRepeat(o, padChar, width - slen);
//     }
//     o.Send(str, slen);
//     if (slen < width && padLeft) {
//       char padChar = padZero ? '0' : ' ';
//       SendRepeat(o, padChar, width - slen);
//     }
//   } }
static int open_log_socket() {   // ToDo: Ideally we want this to fail if the gid of the current   // process is AID_LOGD, but will have to wait until we have   // registered this in private/android_filesystem_config.h. We have   // found that all logd crashes thus far have had no problem stuffing   // the UNIX domain socket and moving on so not critical *today*.
  int log_fd = TEMP_FAILURE_RETRY(socket(PF_UNIX, SOCK_DGRAM | SOCK_CLOEXEC | SOCK_NONBLOCK, 0)); if (log_fd == -1) { return -1; }
  union { struct sockaddr addr; struct sockaddr_un addrUn; } u;  memset(&u, 0, sizeof(u));
  u.addrUn.sun_family = AF_UNIX;
  strlcpy(u.addrUn.sun_path, "/dev/socket/logdw", sizeof(u.addrUn.sun_path)); //strlcpy(u.addrUn.sun_path, "/dev/socket/logdw", sizeof(u.addrUn.sun_path));
  if (TEMP_FAILURE_RETRY(connect(log_fd, &u.addr, sizeof(u.addrUn))) != 0) { __close(log_fd); return -1; }
  return log_fd; }
int async_safe_write_log(int priority, const char* tag, const char* msg) { int main_log_fd = open_log_socket();
  if (main_log_fd == -1) { return -1;//write_stderr(tag, msg); 
  }    // Try stderr instead. 
  iovec vec[6]; char log_id = (priority == ANDROID_LOG_FATAL) ? LOG_ID_CRASH : LOG_ID_MAIN; vec[0].iov_base = &log_id; vec[0].iov_len = sizeof(log_id); uint16_t tid = gettid(); vec[1].iov_base = &tid; vec[1].iov_len = sizeof(tid); timespec ts; 
  clock_gettime(CLOCK_REALTIME, &ts);
  log_time realtime_ts; realtime_ts.tv_sec = ts.tv_sec; realtime_ts.tv_nsec = ts.tv_nsec; vec[2].iov_base = &realtime_ts; vec[2].iov_len = sizeof(realtime_ts); vec[3].iov_base = &priority; vec[3].iov_len = 1;
  vec[4].iov_base = const_cast<char*>(tag); vec[4].iov_len = strlen(tag) + 1; vec[5].iov_base = const_cast<char*>(msg); vec[5].iov_len = strlen(msg) + 1;
  int result = TEMP_FAILURE_RETRY(writev(main_log_fd, vec, sizeof(vec) / sizeof(vec[0]))); //__close(main_log_fd); 
  return result; }
int async_safe_format_log_va_list(int priority, const char* tag, const char* format, va_list args) { //ErrnoRestorer errno_restorer; 
    char buffer[1024] =" dwwwfwf \n"; //   BufferOutputStream os(buffer, sizeof(buffer)); out_vformat(os, format, args);
   return async_safe_write_log(priority, tag, buffer); }
int async_safe_format_log(int priority, const char* tag, const char* format, ...) { va_list args; va_start(args, format);
  int result = async_safe_format_log_va_list(priority, tag, format, args); va_end(args); return result; }
int main(void) { printf(" aaaaaaaaaaaaaaaaaaa \n");
	// int fd=open_log_socket();
    async_safe_format_log(ANDROID_LOG_ERROR, "linker", "Ignoring unknown debug.ld option \"%s\"", "www");
	pause();
}