/// @brief Инструмент для получения имен файлов
class KCInfoFilesFactory
{
    /// @brief Корневая папка разработчика
    const string ROOT_PATH = "KUBC";
    /// @brief Корневая папка настроек мода
    const string MOD_PATH = "INFO";

    /// @brief Создаем папку мода и файл настроек если он не существует
    void CreatePaths()
    {
        MakeDirectory("$profile:"+ROOT_PATH);
        MakeDirectory(GetModPath());
    }

    /// @brief Полный путь к папке мода
    string GetModPath()
    {
        return "$profile:"+ROOT_PATH + "\\" + MOD_PATH;
    }    

}