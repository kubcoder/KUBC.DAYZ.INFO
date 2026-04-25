class KCSuicideInfoConfigFactory
{
    private ref KCInfoFilesFactory filesFactory;

    void KCSuicideInfoConfigFactory(KCInfoFilesFactory files)
    {
        filesFactory = files;
    }

    /// @brief Сохранить конфигурацию в файл 
    /// @param config конфигурация
    void Save(KCSuicideInfoConfig config)
    {
        JsonFileLoader<KCSuicideInfoConfig>.JsonSaveFile(GetFileName(), config);
    }

    /// @brief Загрузить конфигурацию из файла
    /// @return Конфигурация если смогли прочитать файл
    KCSuicideInfoConfig Load()
    {
        KCSuicideInfoConfig result = new KCSuicideInfoConfig();
        string errorMessage = "";
        bool loaded = JsonFileLoader<KCSuicideInfoConfig>.LoadFile(GetFileName(), result, errorMessage);
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
    KCSuicideInfoConfig Build()
    {
        KCSuicideInfoConfig config = Load();
        if (config)
        {
            KCInfo.Log("Загружены настройки " + ConfigFileName);
            return config;
        }
        KCInfo.Log("Не смогли загрузить файл конфигурации "+ConfigFileName+" создаем новый " , KCLogLevel.Warning);
        config = new KCSuicideInfoConfig();
        Save(config);
        return config;
    }

    /// @brief Получить полное имя файла конфигурации
    ///        отправки в чат информации о суицидниках
    const string ConfigFileName = "Suicide.json";

    /// @brief Получить имя файла конфигурации суицидников
    /// @return полное имя файла
    string GetFileName()
    {
        return filesFactory.GetName(ConfigFileName);
    }

}