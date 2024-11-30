/*------------------------------------------------------------------------------
	Enumeration:	directories

	The directory paths in use.
------------------------------------------------------------------------------*/
enum
{
	PATH_CONFIG,
	PATH_LOG,
	PATH_OUTPUT,
	PATH_PROFILE,
	PATH_MAX,		// max number of path names
};
/*------------------------------------------------------------------------------
	Defines:		path list

	This string array is in order for index parsing.
	See (path types)
------------------------------------------------------------------------------*/
#define PATH_STR (const char*[PATH_MAX])			\
{																\
	"Config Directory",						\
	"Log Directory",							\
	"Output Directory",						\ 
	"Profile Directory",					\
}
/*------------------------------------------------------------------------------
	Type: 			dir_struct
	
	Configuration parameters for directory paths.
	
	Members:
	
		pathName		-	string directory path name
------------------------------------------------------------------------------*/
typedef struct
{
	char pathName[MAX_PATHNAME_LEN];

} dir_struct;
