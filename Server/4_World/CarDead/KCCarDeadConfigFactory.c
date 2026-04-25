class KCCarDeadConfigFactory 
{
    private ref KCInfoFilesFactory filesFactory;

    void KCCarDeadConfigFactory(KCInfoFilesFactory files)
    {
        filesFactory = files;
    }

    /// @brief Сохранить конфигурацию в файл 
    /// @param config конфигурация
    void Save(KCCarDeadConfig config)
    {
        JsonFileLoader<KCCarDeadConfig>.JsonSaveFile(GetFileName(), config);
    }

    /// @brief Загрузить конфигурацию из файла
    /// @return Конфигурация если смогли прочитать файл
    KCCarDeadConfig Load()
    {
        KCCarDeadConfig result = new KCCarDeadConfig();
        string errorMessage = "";
        bool loaded = JsonFileLoader<KCCarDeadConfig>.LoadFile(GetFileName(), result, errorMessage);
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
    KCCarDeadConfig Build()
    {
        KCCarDeadConfig config = Load();
        if (config)
        {
            KCInfo.Log("Загружены настройки " + ConfigFileName);
            return config;
        }
        KCInfo.Log("Не смогли загрузить файл конфигурации "+ConfigFileName+" создаем новый " , KCLogLevel.Warning);
        config = new KCCarDeadConfig();
        Save(config);
        return config;
    }

    /// @brief имя файла конфигурации
    const string ConfigFileName = "CarCrash.json";

    /// @brief Получить имя файла конфигурации
    private string GetFileName()
    {
        return filesFactory.GetName(ConfigFileName);
    }
}