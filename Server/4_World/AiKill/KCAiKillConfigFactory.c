class KCAiKillConfigFactory
{
    private ref KCInfoFilesFactory filesFactory;

    void KCAiKillConfigFactory(KCInfoFilesFactory files)
    {
        filesFactory = files;
    }

    /// @brief Сохранить конфигурацию в файл 
    /// @param config конфигурация
    void Save(KCAiKillConfig config)
    {
        JsonFileLoader<KCAiKillConfig>.JsonSaveFile(GetFileName(), config);
    }

    /// @brief Загрузить конфигурацию из файла
    /// @return Конфигурация если смогли прочитать файл
    KCAiKillConfig Load()
    {
        KCAiKillConfig result = new KCAiKillConfig();
        string errorMessage = "";
        bool loaded = JsonFileLoader<KCAiKillConfig>.LoadFile(GetFileName(), result, errorMessage);
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
    KCAiKillConfig Build()
    {
        KCAiKillConfig config = Load();
        if (config)
        {
            KCInfo.Log("Загружены настройки " + ConfigFileName);
            return config;
        }
        KCInfo.Log("Не смогли загрузить файл конфигурации "+ConfigFileName+" создаем новый " , KCLogLevel.Warning);
        config = new KCAiKillConfig();
        Save(config);
        return config;
    }

    /// @brief имя файла конфигурации
    const string ConfigFileName = "AiKill.json";

    /// @brief Получить имя файла конфигурации
    private string GetFileName()
    {
        return filesFactory.GetModPath() + "\\" + ConfigFileName;
    }
}