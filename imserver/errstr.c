#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include <stdlib.h>
#include <errno.h>
#include <string.h>

void printerr()
{	
	switch(errno)
	{
		case EPERM :
			printf("! Operation not permitted.\n");
			break;
		case ENOENT :
			printf("! No such file or directory.\n");
			break;
		case ESRCH :
			printf("! No such process.\n");
			break;
		case EINTR :
			printf("! Interrupted system call.\n");
			break;
		case EIO :
			printf("! I/O error.\n");
			break;
		case ENXIO :
                        printf("! No such device or address.\n");
                        break;
		case E2BIG :
                        printf("! Argument list too long.\n");
                        break;
		case ENOEXEC :
                        printf("! Exec format error.\n");
                        break;
                case EBADF :
                        printf("! Bad file number.\n");
                        break;
                case ECHILD :
                        printf("! No child processes.\n");
                        break;
		case EAGAIN :
                        printf("! Try again.\n");
                        break;
                case ENOMEM :
                        printf("! Out of memory.\n");
                        break;
                case EACCES :
                        printf("! Permission denied.\n");
                        break;
                case EFAULT :
                        printf("! Bad address.\n");
                        break;
                case ENOTBLK :
                        printf("! Block device required.\n");
                        break;
                case EBUSY :
                        printf("! Device or resource busy.\n");
                        break;
		case EEXIST :
                        printf("! File exists.\n");
                        break;
                case EXDEV :
                        printf("! Cross-device link .\n");
                        break;
                case ENODEV :
                        printf("! No such device.\n");
                        break;
                case ENOTDIR :
                        printf("! Not a directory.\n");
                        break;
                case EISDIR :
                        printf("! Is a directory.\n");
                        break;
                case EINVAL :
                        printf("! Invalid argument.\n");
                        break;
                case ENFILE :
                        printf("! File table overflow.\n");
                        break;
                case EMFILE :
                        printf("! Too many open files.\n");
                        break;
                case ENOTTY :
                        printf("! Not a typewriter.\n");
                        break;
                case ETXTBSY :
                        printf("! Text file busy.\n");
                        break;
                case EFBIG :
                        printf("! File too large.\n");
                        break;
		case ENOSPC :
                        printf("! No space left on device.\n");
                        break;
                case ESPIPE :
                        printf("! Illegal seek.\n");
                        break;
                case EROFS :
                        printf("! Read-only file system.\n");
                        break;
                case EMLINK :
                        printf("! Too many links.\n");
                        break;
                case EPIPE :
                        printf("! Broken pipe.\n");
                        break;
                case EDOM :
                        printf("! Math argument out of domain of func.\n");
                        break;
                case ERANGE :
                        printf("! Math result not representable.\n");
                        break;
                case EDEADLK :
                        printf("! Resource deadlock would occur.\n");
                        break;
                case ENAMETOOLONG :
                        printf("! File name too long.\n");
                        break;
                case ENOLCK :
                        printf("! No record locks available.\n");
                        break;
                case ENOSYS :
                        printf("! Function not implemented.\n");
                        break;
		case ENOTEMPTY :
                        printf("! Directory not empty.\n");
                        break;
                case ELOOP :
                        printf("! Too many symbolic links encountered.\n");
                        break;
                case ENOMSG :
                        printf("! No message of desired type.\n");
                        break;
                case EIDRM :
                        printf("! Identifier removed.\n");
                        break;
                case ECHRNG :
                        printf("! Channel number out of range.\n");
                        break;
                case EL2NSYNC :
                        printf("! Level 2 not synchronized.\n");
                        break;
                case EL3HLT :
                        printf("! Level 3 halted.\n");
                        break;
                case EL3RST :
                        printf("! Level 3 reset.\n");
                        break;
                case ELNRNG :
                        printf("! Link number out of range.\n");
                        break;
                case EUNATCH :
                        printf("! Protocol driver not attached.\n");
                        break;
		case ENOCSI :
                        printf("! No CSI structure available.\n");
                        break;
                case EL2HLT :
                        printf("! Level 2 halted.\n");
                        break;
                case EBADE :
                        printf("! Invalid exchange.\n");
                        break;
                case EBADR :
                        printf("! Invalid request descriptor.\n");
                        break;
                case EXFULL :
                        printf("! Exchange full.\n");
                        break;
                case ENOANO :
                        printf("! No anode.\n");
                        break;
                case EBADRQC :
                        printf("! Invalid request code.\n");
                        break;
                case EBADSLT :
                        printf("! Invalid slot.\n");
                        break;
                case EBFONT :
                        printf("! Bad font file format.\n");
                        break;
                case ENOSTR :
                        printf("! Device not a stream.\n");
                        break;
		case ENODATA :
                        printf("! No data available.\n");
                        break;
                case ETIME :
                        printf("! Timer expired.\n");
                        break;
                case ENOSR :
                        printf("! Out of streams resources.\n");
                        break;
                case ENONET :
                        printf("! Machine is not on the network.\n");
                        break;
                case ENOPKG :
                        printf("! Package not installed.\n");
                        break;
                case EREMOTE :
                        printf("! Object is remote.\n");
                        break;
                case ENOLINK :
                        printf("! Link has been severed.\n");
                        break;
                case EADV :
                        printf("! Advertise error.\n");
                        break;
                case ESRMNT :
                        printf("! Srmount error.\n");
                        break;
                case ECOMM :
                        printf("! Communication error on send.\n");
                        break;
                case EPROTO :
                        printf("! Protocol error.\n");
                        break;
		case EMULTIHOP :
			printf("! Multihop attempted.\n");
			break;
		case EDOTDOT :
                        printf("! RFS specific error.\n");
                        break;
		case EBADMSG :
                        printf("! Not a data message.\n");
                        break;
		case EOVERFLOW :
                        printf("! Value too large for defined data type.\n");
                        break;
		case ENOTUNIQ :
                        printf("! Name not unique on network.\n");
                        break;
		case EBADFD :
                        printf("! File descriptor in bad state.\n");
                        break;
                case EREMCHG :
                        printf("! Remote address changed.\n");
                        break;
                case ELIBACC :
                        printf("! Can not access a needed shared library.\n");
                        break;
                case ELIBBAD :
                        printf("! Accessing a corrupted shared library.\n");
                        break;
                case ELIBSCN :
                        printf("! .lib section in a.out corrupted.\n");
                        break;
		case ELIBMAX :
                        printf("! Attempting to link in too many shared libraries.\n");
                        break;
                case ELIBEXEC :
                        printf("! Cannot exec a shared library directly.\n");
                        break;
                case EILSEQ :
                        printf("! Illegal byte sequence.\n");
                        break;
                case ERESTART :
                        printf("! Interrupted system call should be restarted.\n");
                        break;
                case ESTRPIPE :
                        printf("! Streams pipe error.\n");
                        break;
		case EUSERS :
                        printf("! Too many users.\n");
                        break;
                case ENOTSOCK :
                        printf("! Socket operation on non-socket.\n");
                        break;
                case EDESTADDRREQ :
                        printf("! Destination address required.\n");
                        break;
                case EMSGSIZE :
                        printf("! Message too long.\n");
                        break;
                case EPROTOTYPE :
                        printf("! Protocol wrong type for socket.\n");
                        break;
		case ENOPROTOOPT :
                        printf("! Protocol not available.\n");
                        break;
                case EPROTONOSUPPORT :
                        printf("! Protocol not supported.\n");
                        break;
                case ESOCKTNOSUPPORT :
                        printf("! Socket type not supported.\n");
                        break;
                case EOPNOTSUPP :
                        printf("! Operation not supported on transport endpoint.\n");
                        break;
                case EPFNOSUPPORT :
                        printf("! Protocol family not supported.\n");
                        break;
		case EAFNOSUPPORT :
                        printf("! Address family not supported by protocol.\n");
                        break;
                case EADDRINUSE :
                        printf("! Address already in use.\n");
                        break;
                case EADDRNOTAVAIL :
                        printf("! Cannot assign requested address.\n");
                        break;
                case ENETDOWN :
                        printf("! Network is down.\n");
                        break;
                case ENETUNREACH :
                        printf("! Network is unreachable.\n");
                        break;
		case ENETRESET :
                        printf("! Network dropped connection because of reset.\n");
                        break;
                case ECONNABORTED :
                        printf("! Software caused connection abort.\n");
                        break;
                case ECONNRESET :
                        printf("! Connection reset by peer.\n");
                        break;
                case ENOBUFS :
                        printf("! No buffer space available.\n");
                        break;
                case EISCONN :
                        printf("! Transport endpoint is already connected.\n");
                        break;
		case ENOTCONN :
                        printf("! Transport endpoint is not connected.\n");
                        break;
                case ESHUTDOWN :
                        printf("! Cannot send after transport endpoint shutdown.\n");
                        break;
                case ETOOMANYREFS :
                        printf("! Too many references: cannot splice.\n");
                        break;
                case ETIMEDOUT :
                        printf("! Connection timed out.\n");
                        break;
                case ECONNREFUSED :
                        printf("! Connection refused.\n");
                        break;
		case EHOSTDOWN :
                        printf("! Host is down.\n");
                        break;
                case EHOSTUNREACH :
                        printf("! No route to host.\n");
                        break;
                case EALREADY :
                        printf("! Operation already in progress.\n");
                        break;
                case EINPROGRESS :
                        printf("! Operation now in progress.\n");
                        break;
                case ESTALE :
                        printf("! Stale file handle.\n");
                        break;
                case EUCLEAN :
                        printf("! Structure needs cleaning.\n");
                        break;
                case ENOTNAM :
                        printf("! Not a XENIX named type file.\n");
                        break;
                case ENAVAIL :
                        printf("! No XENIX semaphores available.\n");
                        break;
		case EISNAM :
                        printf("! Is a named type file.\n");
                        break;
                case EREMOTEIO :
                        printf("! Remote I/O error.\n");
                        break;
                case EDQUOT :
                        printf("! Quota exceeded.\n");
                        break;
                case ENOMEDIUM :
                        printf("! ENOMEDIUM.\n");
                        break;
                case EMEDIUMTYPE :
                        printf("! Wrong medium type.\n");
                        break;
                case ECANCELED :
                        printf("! Operation Canceled.\n");
                        break;
                case ENOKEY :
                        printf("! Required key not available.\n");
                        break;
                case EKEYEXPIRED :
                        printf("! Key has expired.\n");
                        break;
		case EKEYREVOKED :
                        printf("! Key has been revoked.\n");
                        break;
                case EKEYREJECTED :
                        printf("! Key was rejected by service.\n");
                        break;
                case EOWNERDEAD :
                        printf("! Owner died.\n");
                        break;
                case ENOTRECOVERABLE :
                        printf("! State not recoverable.\n");
                        break;
                case ERFKILL :
                        printf("! Operation not possible due to RF-kill.\n");
                        break;
                case EHWPOISON :
                        printf("! Memory page has hardware error.\n");
                        break;
                default :
			break;

	}

	// #define EDEADLOCK	EDEADLK /* Resource deadlock would occur */
	// #define EWOULDBLOCK	EAGAIN	/* Operation would block */
	
	if (errno == EWOULDBLOCK)
		printf("! Operation would block.\n");
	else if (errno == EDEADLOCK)
		printf("! Resource deadlock would occur.\n");
        else
                printf("! Unsupported errno.\n");
	
}


void errstr(char* s)
{
	s = (char*)calloc(100, sizeof(char));
	strcpy(s, "! Unsupported errno.");
	
	switch(errno)
	{
		case EPERM :
			strcpy(s, "Operation not permitted");
			break;
		case ENOENT :
			strcpy(s, "No such file or directory");
			break;
		case ESRCH :
			strcpy(s, "No such process");
			break;
		case EINTR :
			strcpy(s, "Interrupted system call");
			break;
		case EIO :
			strcpy(s, "I/O error");
			break;
		case ENXIO :
                        strcpy(s, "No such device or address");
                        break;
		case E2BIG :
                        strcpy(s, "Argument list too long");
                        break;
		case ENOEXEC :
                        strcpy(s, "Exec format error");
                        break;
                case EBADF :
                        strcpy(s, "Bad file number");
                        break;
                case ECHILD :
                        strcpy(s, "No child processes");
                        break;
		case EAGAIN :
                        strcpy(s, "Try again");
                        break;
                case ENOMEM :
                        strcpy(s, "Out of memory");
                        break;
                case EACCES :
                        strcpy(s, "Permission denied");
                        break;
                case EFAULT :
                        strcpy(s, "Bad address");
                        break;
                case ENOTBLK :
                        strcpy(s, "Block device required");
                        break;
                case EBUSY :
                        strcpy(s, "Device or resource busy");
                        break;
		case EEXIST :
                        strcpy(s, "File exists");
                        break;
                case EXDEV :
                        strcpy(s, "Cross-device link ");
                        break;
                case ENODEV :
                        strcpy(s, "No such device");
                        break;
                case ENOTDIR :
                        strcpy(s, "Not a directory");
                        break;
                case EISDIR :
                        strcpy(s, "Is a directory");
                        break;
                case EINVAL :
                        strcpy(s, "Invalid argument");
                        break;
                case ENFILE :
                        strcpy(s, "File table overflow");
                        break;
                case EMFILE :
                        strcpy(s, "Too many open files");
                        break;
                case ENOTTY :
                        strcpy(s, "Not a typewriter");
                        break;
                case ETXTBSY :
                        strcpy(s, "Text file busy");
                        break;
                case EFBIG :
                        strcpy(s, "File too large");
                        break;
		case ENOSPC :
                        strcpy(s, "No space left on device");
                        break;
                case ESPIPE :
                        strcpy(s, "Illegal seek");
                        break;
                case EROFS :
                        strcpy(s, "Read-only file system");
                        break;
                case EMLINK :
                        strcpy(s, "Too many links");
                        break;
                case EPIPE :
                        strcpy(s, "Broken pipe");
                        break;
                case EDOM :
                        strcpy(s, "Math argument out of domain of func");
                        break;
                case ERANGE :
                        strcpy(s, "Math result not representable");
                        break;
                case EDEADLK :
                        strcpy(s, "Resource deadlock would occur");
                        break;
                case ENAMETOOLONG :
                        strcpy(s, "File name too long");
                        break;
                case ENOLCK :
                        strcpy(s, "No record locks available");
                        break;
                case ENOSYS :
                        strcpy(s, "Function not implemented");
                        break;
		case ENOTEMPTY :
                        strcpy(s, "Directory not empty");
                        break;
                case ELOOP :
                        strcpy(s, "Too many symbolic links encountered");
                        break;
                case ENOMSG :
                        strcpy(s, "No message of desired type");
                        break;
                case EIDRM :
                        strcpy(s, "Identifier removed");
                        break;
                case ECHRNG :
                        strcpy(s, "Channel number out of range");
                        break;
                case EL2NSYNC :
                        strcpy(s, "Level 2 not synchronized");
                        break;
                case EL3HLT :
                        strcpy(s, "Level 3 halted");
                        break;
                case EL3RST :
                        strcpy(s, "Level 3 reset");
                        break;
                case ELNRNG :
                        strcpy(s, "Link number out of range");
                        break;
                case EUNATCH :
                        strcpy(s, "Protocol driver not attached");
                        break;
		case ENOCSI :
                        strcpy(s, "No CSI structure available");
                        break;
                case EL2HLT :
                        strcpy(s, "Level 2 halted");
                        break;
                case EBADE :
                        strcpy(s, "Invalid exchange");
                        break;
                case EBADR :
                        strcpy(s, "Invalid request descriptor");
                        break;
                case EXFULL :
                        strcpy(s, "Exchange full");
                        break;
                case ENOANO :
                        strcpy(s, "No anode");
                        break;
                case EBADRQC :
                        strcpy(s, "Invalid request code");
                        break;
                case EBADSLT :
                        strcpy(s, "Invalid slot");
                        break;
/*
		case EDEADLOCK EDEADLK :
                        strcpy(s, "");
                        break;
*/
                case EBFONT :
                        strcpy(s, "Bad font file format");
                        break;
                case ENOSTR :
                        strcpy(s, "Device not a stream");
                        break;
		case ENODATA :
                        strcpy(s, "No data available");
                        break;
                case ETIME :
                        strcpy(s, "Timer expired");
                        break;
                case ENOSR :
                        strcpy(s, "Out of streams resources");
                        break;
                case ENONET :
                        strcpy(s, "Machine is not on the network");
                        break;
                case ENOPKG :
                        strcpy(s, "Package not installed");
                        break;
                case EREMOTE :
                        strcpy(s, "Object is remote");
                        break;
                case ENOLINK :
                        strcpy(s, "Link has been severed");
                        break;
                case EADV :
                        strcpy(s, "Advertise error");
                        break;
                case ESRMNT :
                        strcpy(s, "Srmount error");
                        break;
                case ECOMM :
                        strcpy(s, "Communication error on send");
                        break;
                case EPROTO :
                        strcpy(s, "Protocol error");
                        break;
		case EMULTIHOP :
			strcpy(s, "Multihop attempted");
			break;
		case EDOTDOT :
                        strcpy(s, "RFS specific error");
                        break;
		case EBADMSG :
                        strcpy(s, "Not a data message");
                        break;
		case EOVERFLOW :
                        strcpy(s, "Value too large for defined data type");
                        break;
		case ENOTUNIQ :
                        strcpy(s, "Name not unique on network");
                        break;
		case EBADFD :
                        strcpy(s, "File descriptor in bad state");
                        break;
                case EREMCHG :
                        strcpy(s, "Remote address changed");
                        break;
                case ELIBACC :
                        strcpy(s, "Can not access a needed shared library");
                        break;
                case ELIBBAD :
                        strcpy(s, "Accessing a corrupted shared library");
                        break;
                case ELIBSCN :
                        strcpy(s, ".lib section in a.out corrupted");
                        break;
		case ELIBMAX :
                        strcpy(s, "Attempting to link in too many shared libraries");
                        break;
                case ELIBEXEC :
                        strcpy(s, "Cannot exec a shared library directly");
                        break;
                case EILSEQ :
                        strcpy(s, "Illegal byte sequence");
                        break;
                case ERESTART :
                        strcpy(s, "Interrupted system call should be restarted");
                        break;
                case ESTRPIPE :
                        strcpy(s, "Streams pipe error");
                        break;
		case EUSERS :
                        strcpy(s, "Too many users");
                        break;
                case ENOTSOCK :
                        strcpy(s, "Socket operation on non-socket");
                        break;
                case EDESTADDRREQ :
                        strcpy(s, "Destination address required");
                        break;
                case EMSGSIZE :
                        strcpy(s, "Message too long");
                        break;
                case EPROTOTYPE :
                        strcpy(s, "Protocol wrong type for socket");
                        break;
		case ENOPROTOOPT :
                        strcpy(s, "Protocol not available");
                        break;
                case EPROTONOSUPPORT :
                        strcpy(s, "Protocol not supported");
                        break;
                case ESOCKTNOSUPPORT :
                        strcpy(s, "Socket type not supported");
                        break;
                case EOPNOTSUPP :
                        strcpy(s, "Operation not supported on transport endpoint");
                        break;
                case EPFNOSUPPORT :
                        strcpy(s, "Protocol family not supported");
                        break;
		case EAFNOSUPPORT :
                        strcpy(s, "Address family not supported by protocol");
                        break;
                case EADDRINUSE :
                        strcpy(s, "Address already in use");
                        break;
                case EADDRNOTAVAIL :
                        strcpy(s, "Cannot assign requested address");
                        break;
                case ENETDOWN :
                        strcpy(s, "Network is down");
                        break;
                case ENETUNREACH :
                        strcpy(s, "Network is unreachable");
                        break;
		case ENETRESET :
                        strcpy(s, "Network dropped connection because of reset");
                        break;
                case ECONNABORTED :
                        strcpy(s, "Software caused connection abort");
                        break;
                case ECONNRESET :
                        strcpy(s, "Connection reset by peer");
                        break;
                case ENOBUFS :
                        strcpy(s, "No buffer space available");
                        break;
                case EISCONN :
                        strcpy(s, "Transport endpoint is already connected");
                        break;
		case ENOTCONN :
                        strcpy(s, "Transport endpoint is not connected");
                        break;
                case ESHUTDOWN :
                        strcpy(s, "Cannot send after transport endpoint shutdown");
                        break;
                case ETOOMANYREFS :
                        strcpy(s, "Too many references: cannot splice");
                        break;
                case ETIMEDOUT :
                        strcpy(s, "Connection timed out");
                        break;
                case ECONNREFUSED :
                        strcpy(s, "Connection refused");
                        break;
		case EHOSTDOWN :
                        strcpy(s, "Host is down");
                        break;
                case EHOSTUNREACH :
                        strcpy(s, "No route to host");
                        break;
                case EALREADY :
                        strcpy(s, "Operation already in progress");
                        break;
                case EINPROGRESS :
                        strcpy(s, "Operation now in progress");
                        break;
                case ESTALE :
                        strcpy(s, "Stale file handle");
                        break;
                case EUCLEAN :
                        strcpy(s, "Structure needs cleaning");
                        break;
                case ENOTNAM :
                        strcpy(s, "Not a XENIX named type file");
                        break;
                case ENAVAIL :
                        strcpy(s, "No XENIX semaphores available");
                        break;
		case EISNAM :
                        strcpy(s, "Is a named type file");
                        break;
                case EREMOTEIO :
                        strcpy(s, "Remote I/O error");
                        break;
                case EDQUOT :
                        strcpy(s, "Quota exceeded");
                        break;
                case ENOMEDIUM :
                        strcpy(s, "ENOMEDIUM");
                        break;
                case EMEDIUMTYPE :
                        strcpy(s, "Wrong medium type");
                        break;
                case ECANCELED :
                        strcpy(s, "Operation Canceled");
                        break;
                case ENOKEY :
                        strcpy(s, "Required key not available");
                        break;
                case EKEYEXPIRED :
                        strcpy(s, "Key has expired");
                        break;
		case EKEYREVOKED :
                        strcpy(s, "Key has been revoked");
                        break;
                case EKEYREJECTED :
                        strcpy(s, "Key was rejected by service");
                        break;
                case EOWNERDEAD :
                        strcpy(s, "Owner died");
                        break;
                case ENOTRECOVERABLE :
                        strcpy(s, "State not recoverable");
                        break;
                case ERFKILL :
                        strcpy(s, "Operation not possible due to RF-kill");
                        break;
                case EHWPOISON :
                        strcpy(s, "Memory page has hardware error");
                        break;
                default :
			break;

	}

	// #define	EDEADLOCK	EDEADLK /* Resource deadlock would occur */
	// #define	EWOULDBLOCK	EAGAIN	/* Operation would block */
	if (errno == EWOULDBLOCK)
		strcpy(s, "Operation would block");
	else if (errno == EDEADLOCK)
		strcpy(s, "Resource deadlock would occur");


	return;
}


