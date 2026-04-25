/// @brief Инструмент для получения имен файлов
class KCInfoFilesFactory : KCDirectory
{
    
    /// @brief Корневая папка настроек мода
    const string MOD_PATH = "INFO";

    void KCInfoFilesFactory()
    {
        pathNames.Insert(MOD_PATH);
    }

}