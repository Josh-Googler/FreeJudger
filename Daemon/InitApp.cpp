#include "InitApp.h"

#include <Windows.h>

#include "../judgerlib/logger/Logger.h"
#include "../judgerlib/logger/Logger_log4cxx.h"
#include "../judgerlib/config/AppConfig.h"

namespace IMUST
{

bool InitApp()
{
    if (!details::InitLogger())
    {
        MessageBoxW(NULL, L"��ʼ����־ϵͳʧ��", L"����", MB_OK);
        return false;
    }


    if (!details::InitAppConfig())
    {
        MessageBoxW(NULL, L"��ʼ���������ü�ʧ�ܣ��������־", L"����", MB_OK);
        return false;
    }

    return true;
}

namespace details
{

bool InitLogger()
{
    try
    {
        IMUST::LoggerFactory::registerLogger(
            new IMUST::Log4CxxLoggerImpl(GetOJString("log.cfg"), GetOJString("logger1")), 
            IMUST::LoggerId::AppInitLoggerId);
    }
    catch (...)
    {
        return false;
    }

    return true;
}

bool InitAppConfig()
{
    return ::IMUST::AppConfig::InitAppConfig();
}

}   // namespace details





}   // namespace IMUST