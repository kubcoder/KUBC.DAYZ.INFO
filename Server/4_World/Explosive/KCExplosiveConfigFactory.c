class KCExplosiveConfigFactory
{
    private ref KCInfoFilesFactory filesFactory;

    void KCExplosiveConfigFactory(KCInfoFilesFactory files)
    {
        filesFactory = files;
    }

    /// @brief Сохранить конфигурацию в файл 
    /// @param config конфигурация
    void Save(KCExplosiveConfig config)
    {
        JsonFileLoader<KCExplosiveConfig>.JsonSaveFile(GetFileName(), config);
    }

    /// @brief Загрузить конфигурацию из файла
    /// @return Конфигурация если смогли прочитать файл
    KCExplosiveConfig Load()
    {
        KCExplosiveConfig result = new KCExplosiveConfig();
        string errorMessage = "";
        bool loaded = JsonFileLoader<KCExplosiveConfig>.LoadFile(GetFileName(), result, errorMessage);
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
    KCExplosiveConfig Build()
    {
        KCExplosiveConfig config = Load();
        if (config)
        {
            KCInfo.Log("Загружены настройки " + ConfigFileName);
            return config;
        }
        KCInfo.Log("Не смогли загрузить файл конфигурации "+ConfigFileName+" создаем новый " , KCLogLevel.Warning);
        config = new KCExplosiveConfig();
        Save(config);
        return config;
    }

    /// @brief Получить полное имя файла конфигурации
    const string ConfigFileName = "Explosive.json";

    /// @brief Получить имя файла конфигурации количества игроков
    /// @return полное имя файла
    string GetFileName()
    {
        return filesFactory.GetName(ConfigFileName);
    }
}