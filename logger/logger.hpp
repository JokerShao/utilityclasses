#ifndef _LOGGER_H__
#define _LOGGER_H__
 
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
 
 
 
class Logger
{
public:
    Log();
    ~Log();
 
    bool Open(string strFileName);
    void Close();
 
    bool CommonLogInit(); //打开默认的log 文件
 
    void Enable();
    void Disable();
 
    string GetTimeStr();
 
    template <typename T> void LogOut(const T& value)
    {
        if (m_bEnabled)
        {
            m_tOLogFile << value;
        }
    }
 
    template <typename T> void LogOutLn(const T& value)
    {
        if (m_bEnabled)
        {
            m_tOLogFile << value << endl;
        }
    }
 
    void LogOutLn()
    {
        if (m_bEnabled)
        {
            m_tOLogFile << endl;
        }
    }
 
    template <typename T> Log& operator<<(const T& value)
    {
        if (m_bEnabled)
        {
            m_tOLogFile << value;
        }
        return (*this);
    }
 
    Log& operator<<(ostream& (*_Pfn)(ostream&))
    {
        if (m_bEnabled)
        {
            (*_Pfn)(m_tOLogFile);
        }
        return (*this);
    }
 
private:
    template<typename T> string ValueToStr(T value)
    {
        ostringstream ost;
        ost << value;
        return ost.str();
    }
private:
    ofstream m_tOLogFile;
 
    bool m_bEnabled;
};
 
 
#endif
 
//========================
//Log.cpp
 
#include "Log.h"
 
Log::Log()
    :m_bEnabled(true)
{
}
 
Log::~Log()
{
}
 
bool Log::Open(string sFileName)
{
    m_tOLogFile.open(sFileName.c_str(), ios_base::out | ios_base::app);
 
    if( !m_tOLogFile )
    {
        return false;
    }
 
    return true;
}
 
void Log::Close()
{
    if(m_tOLogFile.is_open())
    {
        m_tOLogFile.close();
    }
}
 
bool Log::CommonLogInit()
{
    time_t tNowTime;
    time(&tNowTime);
 
    tm* tLocalTime = localtime(&tNowTime);
 
    //得到日期的字符串
    string sDateStr = ValueToStr(tLocalTime->tm_year+1900) + "-" +
        ValueToStr(tLocalTime->tm_mon+1) + "-" +
        ValueToStr(tLocalTime->tm_mday);
 
    return Open("Log_" + sDateStr + ".log");
}
 
void Log::Enable()
{
    m_bEnabled = true;
}
 
void Log::Disable()
{
    m_bEnabled = false;
}
 
//得到当前时间的字符串
string Log::GetTimeStr()
{
    time_t tNowTime;
    time(&tNowTime);
 
    tm* tLocalTime = localtime(&tNowTime);
 
    //"2011-07-18 23:03:01 ";
    string strFormat = "%Y-%m-%d %H:%M:%S ";
 
    char strDateTime[30] = {'\0'};
    strftime(strDateTime, 30, strFormat.c_str(), tLocalTime);
 
    string strRes = strDateTime;
 
    return strRes;
}
 
//本Log类,用于一般简单的Log文本文件输出.
 
//test: main.cpp
#include "Log.h"
 
int main()
{
    Log mainLog;
    mainLog.CommonLogInit();
 
    mainLog << mainLog.GetTimeStr() << "测试Log类." << endl;
}
