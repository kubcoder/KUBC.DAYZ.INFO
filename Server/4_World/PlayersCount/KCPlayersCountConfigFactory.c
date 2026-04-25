/// @brief Фабрика доступа к файлу конфигурации
///        настроек информации о количестве игроков
class KCPlayersCountConfigFactory
{
    private ref KCInfoFilesFactory filesFactory;

    void KCPlayersCountConfigFactory(KCInfoFilesFactory files)
    {
        filesFactory = files;
    }

    /// @brief Сохранить конфигурацию в файл 
    /// @param config конфигурация
    void Save(KCPlayersCountConfig config)
    {
        JsonFileLoader<KCPlayersCountConfig>.JsonSaveFile(GetFileName(), config);
    }

    /// @brief Загрузить конфигурацию из файла
    /// @return Конфигурация если смогли прочитать файл
    KCPlayersCountConfig Load()
    {
        KCPlayersCountConfig result = new KCPlayersCountConfig();
        string errorMessage = "";
        bool loaded = JsonFileLoader<KCPlayersCountConfig>.LoadFile(GetFileName(), result, errorMessage);
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
    KCPlayersCountConfig Build()
    {
        KCPlayersCountConfig config = Load();
        if (config)
        {
            KCInfo.Log("Загружены настройки " + ConfigFileName);
            return config;
        }
        KCInfo.Log("Не смогли загрузить файл конфигурации "+ConfigFileName+" создаем новый " , KCLogLevel.Warning);
        config = new KCPlayersCountConfig();
        Save(config);
        return config;
    }

    /// @brief Получить полное имя файла конфигурации
    ///        отправки в чат информации о колличестве игроков
    const string ConfigFileName = "PlayersCount.json";

    /// @brief Получить имя файла конфигурации количества игроков
    /// @return полное имя файла
    string GetFileName()
    {
        return filesFactory.GetName(ConfigFileName);
    }
}