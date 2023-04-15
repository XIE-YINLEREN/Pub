// Don't modify this file as it will be overwritten.
//
#include "CDR/CDR.h"
#include "ReturnCode.h"
#include "BasicTypes.h"

#ifndef IDL_UserDataType_hh
#define IDL_UserDataType_hh

#ifndef UserDataType_defined
#define UserDataType_defined

struct UserDataType {
  UserDataType()
	{
		
		color = new char[1024];
		data = new char[1024];
		data[0] = '\0';
		color[0]= '\0';
		num = 0;
	}

  UserDataType(const UserDataType  &IDL_s);

  ~UserDataType(){
		delete color;
		delete data;
		data = NULL;
		color = NULL;
	}

  	int StructSize()
	{
		int strSize = 0;
		strSize += sizeof(UserDataType);
		strSize += strlen(color);
		strSize += strlen(data);
		return strSize;
	}
	UserDataType& operator= (const UserDataType &IDL_s);

	void Marshal(CDR *cdr) const;
	void UnMarshal(CDR *cdr);
	char* data;
	char* color;
	long int num;
};

typedef sequence<UserDataType> UserDataTypeSeq;

#endif




#endif /*IDL_UserDataType_hh */
