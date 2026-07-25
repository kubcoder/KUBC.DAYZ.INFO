/// @brief Фабрика доступа к файлу конфигурации 
///        настроек информации о подключении/отключении
class KCConnectInfoConfigFactory
{
    private ref KCInfoFilesFactory filesFactory;

    void KCConnectInfoConfigFactory(KCInfoFilesFactory files)
    {
        filesFactory = files;
    }

    /// @brief Сохранить конфигурацию в файл 
    /// @param config конфигурация
    void Save(KCConnectionInfoConfig config)
    {
        JsonFileLoader<KCConnectionInfoConfig>.JsonSaveFile(GetFileName(), config);
    }

    /// @brief Загрузить конфигурацию из файла
    /// @return Конфигурация если смогли прочитать файл
    KCConnectionInfoConfig Load()
    {
        KCConnectionInfoConfig result = new KCConnectionInfoConfig();
        string errorMessage = "";
        bool loaded = JsonFileLoader<KCConnectionInfoConfig>.LoadFile(GetFileName(), result, errorMessage);
        if(loaded)
        {
            return result;
        }
        else 
        {
            KCInfo.Log("Ошибка загрузки файла " + ConfigFileName + ": "+ errorMessage, KCLogLevel.Error);
        }
        return NULL;
    }

    /// @brief Получить конфигурацию из файла. Если файла нет или он не читается
    ///        создается новый файл конфигурации по умолчанию
    /// @return 
    KCConnectionInfoConfig Build()
    {
        KCConnectionInfoConfig config = Load();
        if (config)
        {
            KCInfo.Log("Загружены настройки " + ConfigFileName);
            return config;
        }
        KCInfo.Log("Не смогли загрузить файл конфигурации "+ConfigFileName+" создаем новый " , KCLogLevel.Warning);
        config = new KCConnectionInfoConfig();
        Save(config);
        return config;
    }

    /// @brief Получить полное имя файла конфигурации
    ///        отправки в чат информации о подключении/отключении
    ///        игрока
    const string ConfigFileName = "Connect.json";

    /// @brief Получить имя файла конфигурации подключения/отключения игроков
    /// @return полное имя файла
    string GetFileName()
    {
        return filesFactory.GetName(ConfigFileName);
    }
}