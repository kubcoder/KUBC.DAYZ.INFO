class KCPlayerKillConfigFactory
{
    private ref KCInfoFilesFactory filesFactory;

    void KCPlayerKillConfigFactory(KCInfoFilesFactory files)
    {
        filesFactory = files;
    }

    /// @brief Сохранить конфигурацию в файл 
    /// @param config конфигурация
    void Save(KCPlayerKillConfig config)
    {
        JsonFileLoader<KCPlayerKillConfig>.JsonSaveFile(GetFileName(), config);
    }

    /// @brief Загрузить конфигурацию из файла
    /// @return Конфигурация если смогли прочитать файл
    KCPlayerKillConfig Load()
    {
        KCPlayerKillConfig result = new KCPlayerKillConfig();
        string errorMessage = "";
        bool loaded = JsonFileLoader<KCPlayerKillConfig>.LoadFile(GetFileName(), result, errorMessage);
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
    KCPlayerKillConfig Build()
    {
        KCPlayerKillConfig config = Load();
        if (config)
        {
            KCInfo.Log("Загружены настройки " + ConfigFileName);
            return config;
        }
        KCInfo.Log("Не смогли загрузить файл конфигурации "+ConfigFileName+" создаем новый " , KCLogLevel.Warning);
        config = new KCPlayerKillConfig();
        Save(config);
        return config;
    }

    /// @brief Получить полное имя файла конфигурации
    ///        отправки в чат информации о убийстве игроками
    const string ConfigFileName = "PlayerKill.json";

    /// @brief Получить имя файла конфигурации убийстве игроками
    /// @return полное имя файла
    private string GetFileName()
    {
        return filesFactory.GetName(ConfigFileName);
    }
}