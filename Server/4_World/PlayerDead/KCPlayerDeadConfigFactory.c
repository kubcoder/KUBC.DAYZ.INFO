class KCPlayerDeadConfigFactory
{
    private ref KCInfoFilesFactory filesFactory;

    void KCPlayerDeadConfigFactory(KCInfoFilesFactory files)
    {
        filesFactory = files;
    }

    /// @brief Сохранить конфигурацию в файл 
    /// @param config конфигурация
    void Save(KCPlayerDeadConfig config)
    {
        JsonFileLoader<KCPlayerDeadConfig>.JsonSaveFile(GetFileName(), config);
    }

    /// @brief Загрузить конфигурацию из файла
    /// @return Конфигурация если смогли прочитать файл
    KCPlayerDeadConfig Load()
    {
        KCPlayerDeadConfig result = new KCPlayerDeadConfig();
        string errorMessage = "";
        bool loaded = JsonFileLoader<KCPlayerDeadConfig>.LoadFile(GetFileName(), result, errorMessage);
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
    KCPlayerDeadConfig Build()
    {
        KCPlayerDeadConfig config = Load();
        if (config)
        {
            KCInfo.Log("Загружены настройки " + ConfigFileName);
            return config;
        }
        KCInfo.Log("Не смогли загрузить файл конфигурации "+ConfigFileName+" создаем новый " , KCLogLevel.Warning);
        config = new KCPlayerDeadConfig();
        Save(config);
        return config;
    }

    /// @brief Получить полное имя файла конфигурации
    const string ConfigFileName = "PlayerDead.json";

    /// @brief Получить имя файла конфигурации
    /// @return полное имя файла
    string GetFileName()
    {
        return filesFactory.GetModPath() + "\\" + ConfigFileName;
    }
}