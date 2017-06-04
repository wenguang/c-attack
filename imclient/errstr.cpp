#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

void printerr()
{	
	switch(errno)
	{
		case EPERM :
			printf("! errno: Operation not permitted.\n");
			break;
		case ENOENT :
			printf("! errno: No such file or directory.\n");
			break;
		case ESRCH :
			printf("! errno: No such process.\n");
			break;
		case EINTR :
			printf("! errno: Interrupted system call.\n");
			break;
		case EIO :
			printf("! errno: I/O error.\n");
			break;
		case ENXIO :
                        printf("! errno: No such device or address.\n");
                        break;
		case E2BIG :
                        printf("! errno: Argument list too long.\n");
                        break;
		case ENOEXEC :
                        printf("! errno: Exec format error.\n");
                        break;
                case EBADF :
                        printf("! errno: Bad file number.\n");
                        break;
                case ECHILD :
                        printf("! errno: No child processes.\n");
                        break;
		case EAGAIN :
                        printf("! errno: Try again.\n");
                        break;
                case ENOMEM :
                        printf("! errno: Out of memory.\n");
                        break;
                case EACCES :
                        printf("! errno: Permission denied.\n");
                        break;
                case EFAULT :
                        printf("! errno: Bad address.\n");
                        break;
                case ENOTBLK :
                        printf("! errno: Block device required.\n");
                        break;
                case EBUSY :
                        printf("! errno: Device or resource busy.\n");
                        break;
		case EEXIST :
                        printf("! errno: File exists.\n");
                        break;
                case EXDEV :
                        printf("! errno: Cross-device link .\n");
                        break;
                case ENODEV :
                        printf("! errno: No such device.\n");
                        break;
                case ENOTDIR :
                        printf("! errno: Not a directory.\n");
                        break;
                case EISDIR :
                        printf("! errno: Is a directory.\n");
                        break;
                case EINVAL :
                        printf("! errno: Invalid argument.\n");
                        break;
                case ENFILE :
                        printf("! errno: File table overflow.\n");
                        break;
                case EMFILE :
                        printf("! errno: Too many open files.\n");
                        break;
                case ENOTTY :
                        printf("! errno: Not a typewriter.\n");
                        break;
                case ETXTBSY :
                        printf("! errno: Text file busy.\n");
                        break;
                case EFBIG :
                        printf("! errno: File too large.\n");
                        break;
		case ENOSPC :
                        printf("! errno: No space left on device.\n");
                        break;
                case ESPIPE :
                        printf("! errno: Illegal seek.\n");
                        break;
                case EROFS :
                        printf("! errno: Read-only file system.\n");
                        break;
                case EMLINK :
                        printf("! errno: Too many links.\n");
                        break;
                case EPIPE :
                        printf("! errno: Broken pipe.\n");
                        break;
                case EDOM :
                        printf("! errno: Math argument out of domain of func.\n");
                        break;
                case ERANGE :
                        printf("! errno: Math result not representable.\n");
                        break;
                case EDEADLK :
                        printf("! errno: Resource deadlock would occur.\n");
                        break;
                case ENAMETOOLONG :
                        printf("! errno: File name too long.\n");
                        break;
                case ENOLCK :
                        printf("! errno: No record locks available.\n");
                        break;
                case ENOSYS :
                        printf("! errno: Function not implemented.\n");
                        break;
		case ENOTEMPTY :
                        printf("! errno: Directory not empty.\n");
                        break;
                case ELOOP :
                        printf("! errno: Too many symbolic links encountered.\n");
                        break;
                case ENOMSG :
                        printf("! errno: No message of desired type.\n");
                        break;
                case EIDRM :
                        printf("! errno: Identifier removed.\n");
                        break;
                case ECHRNG :
                        printf("! errno: Channel number out of range.\n");
                        break;
                case EL2NSYNC :
                        printf("! errno: Level 2 not synchronized.\n");
                        break;
                case EL3HLT :
                        printf("! errno: Level 3 halted.\n");
                        break;
                case EL3RST :
                        printf("! errno: Level 3 reset.\n");
                        break;
                case ELNRNG :
                        printf("! errno: Link number out of range.\n");
                        break;
                case EUNATCH :
                        printf("! errno: Protocol driver not attached.\n");
                        break;
		case ENOCSI :
                        printf("! errno: No CSI structure available.\n");
                        break;
                case EL2HLT :
                        printf("! errno: Level 2 halted.\n");
                        break;
                case EBADE :
                        printf("! errno: Invalid exchange.\n");
                        break;
                case EBADR :
                        printf("! errno: Invalid request descriptor.\n");
                        break;
                case EXFULL :
                        printf("! errno: Exchange full.\n");
                        break;
                case ENOANO :
                        printf("! errno: No anode.\n");
                        break;
                case EBADRQC :
                        printf("! errno: Invalid request code.\n");
                        break;
                case EBADSLT :
                        printf("! errno: Invalid slot.\n");
                        break;
                case EBFONT :
                        printf("! errno: Bad font file format.\n");
                        break;
                case ENOSTR :
                        printf("! errno: Device not a stream.\n");
                        break;
		case ENODATA :
                        printf("! errno: No data available.\n");
                        break;
                case ETIME :
                        printf("! errno: Timer expired.\n");
                        break;
                case ENOSR :
                        printf("! errno: Out of streams resources.\n");
                        break;
                case ENONET :
                        printf("! errno: Machine is not on the network.\n");
                        break;
                case ENOPKG :
                        printf("! errno: Package not installed.\n");
                        break;
                case EREMOTE :
                        printf("! errno: Object is remote.\n");
                        break;
                case ENOLINK :
                        printf("! errno: Link has been severed.\n");
                        break;
                case EADV :
                        printf("! errno: Advertise error.\n");
                        break;
                case ESRMNT :
                        printf("! errno: Srmount error.\n");
                        break;
                case ECOMM :
                        printf("! errno: Communication error on send.\n");
                        break;
                case EPROTO :
                        printf("! errno: Protocol error.\n");
                        break;
		case EMULTIHOP :
			printf("! errno: Multihop attempted.\n");
			break;
		case EDOTDOT :
                        printf("! errno: RFS specific error.\n");
                        break;
		case EBADMSG :
                        printf("! errno: Not a data message.\n");
                        break;
		case EOVERFLOW :
                        printf("! errno: Value too large for defined data type.\n");
                        break;
		case ENOTUNIQ :
                        printf("! errno: Name not unique on network.\n");
                        break;
		case EBADFD :
                        printf("! errno: File descriptor in bad state.\n");
                        break;
                case EREMCHG :
                        printf("! errno: Remote address changed.\n");
                        break;
                case ELIBACC :
                        printf("! errno: Can not access a needed shared library.\n");
                        break;
                case ELIBBAD :
                        printf("! errno: Accessing a corrupted shared library.\n");
                        break;
                case ELIBSCN :
                        printf("! errno: .lib section in a.out corrupted.\n");
                        break;
		case ELIBMAX :
                        printf("! errno: Attempting to link in too many shared libraries.\n");
                        break;
                case ELIBEXEC :
                        printf("! errno: Cannot exec a shared library directly.\n");
                        break;
                case EILSEQ :
                        printf("! errno: Illegal byte sequence.\n");
                        break;
                case ERESTART :
                        printf("! errno: Interrupted system call should be restarted.\n");
                        break;
                case ESTRPIPE :
                        printf("! errno: Streams pipe error.\n");
                        break;
		case EUSERS :
                        printf("! errno: Too many users.\n");
                        break;
                case ENOTSOCK :
                        printf("! errno: Socket operation on non-socket.\n");
                        break;
                case EDESTADDRREQ :
                        printf("! errno: Destination address required.\n");
                        break;
                case EMSGSIZE :
                        printf("! errno: Message too long.\n");
                        break;
                case EPROTOTYPE :
                        printf("! errno: Protocol wrong type for socket.\n");
                        break;
		case ENOPROTOOPT :
                        printf("! errno: Protocol not available.\n");
                        break;
                case EPROTONOSUPPORT :
                        printf("! errno: Protocol not supported.\n");
                        break;
                case ESOCKTNOSUPPORT :
                        printf("! errno: Socket type not supported.\n");
                        break;
                case EOPNOTSUPP :
                        printf("! errno: Operation not supported on transport endpoint.\n");
                        break;
                case EPFNOSUPPORT :
                        printf("! errno: Protocol family not supported.\n");
                        break;
		case EAFNOSUPPORT :
                        printf("! errno: Address family not supported by protocol.\n");
                        break;
                case EADDRINUSE :
                        printf("! errno: Address already in use.\n");
                        break;
                case EADDRNOTAVAIL :
                        printf("! errno: Cannot assign requested address.\n");
                        break;
                case ENETDOWN :
                        printf("! errno: Network is down.\n");
                        break;
                case ENETUNREACH :
                        printf("! errno: Network is unreachable.\n");
                        break;
		case ENETRESET :
                        printf("! errno: Network dropped connection because of reset.\n");
                        break;
                case ECONNABORTED :
                        printf("! errno: Software caused connection abort.\n");
                        break;
                case ECONNRESET :
                        printf("! errno: Connection reset by peer.\n");
                        break;
                case ENOBUFS :
                        printf("! errno: No buffer space available.\n");
                        break;
                case EISCONN :
                        printf("! errno: Transport endpoint is already connected.\n");
                        break;
		case ENOTCONN :
                        printf("! errno: Transport endpoint is not connected.\n");
                        break;
                case ESHUTDOWN :
                        printf("! errno: Cannot send after transport endpoint shutdown.\n");
                        break;
                case ETOOMANYREFS :
                        printf("! errno: Too many references: cannot splice.\n");
                        break;
                case ETIMEDOUT :
                        printf("! errno: Connection timed out.\n");
                        break;
                case ECONNREFUSED :
                        printf("! errno: Connection refused.\n");
                        break;
		case EHOSTDOWN :
                        printf("! errno: Host is down.\n");
                        break;
                case EHOSTUNREACH :
                        printf("! errno: No route to host.\n");
                        break;
                case EALREADY :
                        printf("! errno: Operation already in progress.\n");
                        break;
                case EINPROGRESS :
                        printf("! errno: Operation now in progress.\n");
                        break;
                case ESTALE :
                        printf("! errno: Stale file handle.\n");
                        break;
                case EUCLEAN :
                        printf("! errno: Structure needs cleaning.\n");
                        break;
                case ENOTNAM :
                        printf("! errno: Not a XENIX named type file.\n");
                        break;
                case ENAVAIL :
                        printf("! errno: No XENIX semaphores available.\n");
                        break;
		case EISNAM :
                        printf("! errno: Is a named type file.\n");
                        break;
                case EREMOTEIO :
                        printf("! errno: Remote I/O error.\n");
                        break;
                case EDQUOT :
                        printf("! errno: Quota exceeded.\n");
                        break;
                case ENOMEDIUM :
                        printf("! errno: ENOMEDIUM.\n");
                        break;
                case EMEDIUMTYPE :
                        printf("! errno: Wrong medium type.\n");
                        break;
                case ECANCELED :
                        printf("! errno: Operation Canceled.\n");
                        break;
                case ENOKEY :
                        printf("! errno: Required key not available.\n");
                        break;
                case EKEYEXPIRED :
                        printf("! errno: Key has expired.\n");
                        break;
		case EKEYREVOKED :
                        printf("! errno: Key has been revoked.\n");
                        break;
                case EKEYREJECTED :
                        printf("! errno: Key was rejected by service.\n");
                        break;
                case EOWNERDEAD :
                        printf("! errno: Owner died.\n");
                        break;
                case ENOTRECOVERABLE :
                        printf("! errno: State not recoverable.\n");
                        break;
                case ERFKILL :
                        printf("! errno: Operation not possible due to RF-kill.\n");
                        break;
                case EHWPOISON :
                        printf("! errno: Memory page has hardware error.\n");
                        break;
                default :
			break;

	}

	// #define EDEADLOCK	EDEADLK /* Resource deadlock would occur */
	// #define EWOULDBLOCK	EAGAIN	/* Operation would block */
	
	if (errno == EWOULDBLOCK)
		printf("! errno: Operation would block.\n");
	else if (errno == EDEADLOCK)
		printf("! errno: Resource deadlock would occur.\n");
	
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


