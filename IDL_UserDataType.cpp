// Don't modify this file as it will be overwritten.
//
#include "IDL_UserDataType.h"

UserDataType::UserDataType(const UserDataType &IDL_s){
  data = IDL_s.data;
  color = IDL_s.color;
  num = IDL_s.num;
}

UserDataType& UserDataType::operator= (const UserDataType &IDL_s){
  if (this == &IDL_s) return *this;
  data = IDL_s.data;
  color = IDL_s.color;
  num = IDL_s.num;
  return *this;
}

void UserDataType::Marshal(CDR *cdr) const {
  cdr->PutString(data);
  cdr->PutString(color);
  cdr->PutLong(num);
}

void UserDataType::UnMarshal(CDR *cdr)
{
    char *IDL_str;
    char* IDL_Data;
    cdr->GetString(IDL_str);
    cdr->GetString(IDL_Data);
    cdr->GetLong(num);
    if(color != NULL )
    {
        delete color;
        delete data;
        color = NULL;
        data = NULL;
    }
    color = IDL_str;
    data = IDL_Data;
}

