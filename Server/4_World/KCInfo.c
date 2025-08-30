class KCInfo
{
    /// @brief Имя мода в локах
    static const string MOD_NAME = "KUBC.INFO";
    
    /// @brief Записать в лог скриптов сообщение от мода
    /// @param Message Текст сообщения
    /// @param Level Уровень сообщения
    static void Log(string Message, KCLogLevel Level = KCLogLevel.Info)
    {
        KCLog.Write(MOD_NAME, Message, Level);
    }

    /// @brief Записать в лог админов сообщение от мода
    /// @param Message Текст сообщения
    /// @param Level Уровень сообщения
    static void LogAdm(string Message, KCLogLevel Level = KCLogLevel.Info)
    {
        KCLog.WriteADM(MOD_NAME, Message, Level);
    }
    
}