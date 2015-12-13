#ifndef DEFINES_H
#define DEFINES_H

#include <QDebug>
#include <QObject>
#include <QString>
#include <QVector>
#include <QList>
#include <QThread>
#include <QMutex>
#include <QMap>
#include <QSet>
#include <QDateTime>
#include <QTextStream>
#include <assert.h>

const int MAX_OPEN_ROWS=0;
//const int MAX_OPEN_IN_ROWS=0; //moved in ExcelWidget

enum TypeOfRow
{
    BASE_TYPE = 1,
    INPUT_TYPE = 2
};

enum TypeOfData
{
    RAW = 1,
    PARSED = 2
};

enum AddressElements
{
    STREET=1,      ///< название ул. (пр., ш., бул. и пр.)
    STREET_ID,     ///< id ул.
    KORP,          ///< корпус
    BUILD,         ///< дом
    BUILD_ID,      ///< id дома
    ENAME,         ///< element name (элементарное имя) (ул., пр., ш., бул. и пр.)
    ADDITIONAL,    ///< допольнительная информация

    CITY,          ///< город
    DISTRICT,      ///< район
    FSUBJ,         ///< federal subject (федеральный субъект) (название области, края, республики и пр.)
    RAW_ADDR,      ///< "сырой" адрес (тот который был прочитан из файла сsv)
};

const QList<AddressElements> ListMandatoryAddressElements {
    STREET, STREET_ID, BUILD_ID
};

const QList<AddressElements> ListAddressElements {
    STREET, STREET_ID, KORP, BUILD, BUILD_ID, ENAME, ADDITIONAL,
            CITY, DISTRICT, FSUBJ
};

typedef QMap<AddressElements, int> MapAddressElementPosition;

//key of map - sheet name, value - list of rows, row - string list
typedef QList< QStringList > ExcelSheet;
typedef QMap<QString, ExcelSheet > ExcelDocument;


typedef QVector<QString> VectorOfString;

const QMap<AddressElements, QString> MapColumnNames {
    {STREET, "STREET"},
    {STREET_ID, "STRT_ID"},
    {KORP, "KORP"},
    {BUILD, "BLD"},
    {BUILD_ID, "BLD_ID"},
    {ENAME, "ENAME"},
    {ADDITIONAL, "ADD"},
    {CITY, "CITY"},
    {DISTRICT, "DISTRICT"},
    {FSUBJ, "FSUBJ"},
    {RAW_ADDR, "RAW"},
};

const QMap<AddressElements, QString> MapColumnParsedNames {
    {STREET, "!P_STREET"},
    {STREET_ID, "!P_STRT_ID"},
    {KORP, "!P_KORP"},
    {BUILD, "!P_BLD"},
    {BUILD_ID, "!P_BLD_ID"},
    {ENAME, "!P_ENAME"},
    {ADDITIONAL, "!P_ADD"},
    {CITY, "!P_CITY"},
    {DISTRICT, "!P_DISTRICT"},
    {FSUBJ, "!P_FSUBJ"},
};

enum Errors
{
    XLS_WORKER_ERROR=1,
};

const QVector<QString> Cities {
    "Аврово",
    "Агалатово",
    "Алексеевка",
    "Алексино",
    "Алеховщина",
    "Андреево",
    "Андреевщина",
    "Андрианово",
    "Андронниково",
    "Анисимово",
    "Аннино",
    "Апраксин Бор",
    "Бабино",
    "Батово",
    "Бегуницы",
    "Белогорка",
    "Белое",
    "Бережки",
    "Березовик",
    "Беседа",
    "Бокситогорск",
    "Большая Вруда",
    "Большая Ижора",
    "Большая Пустомержа",
    "Большие Коковичи",
    "Большие Колпаны",
    "Большие Сабицы",
    "Большие Шатновичи",
    "Большое Жабино",
    "Большое Куземкино",
    "Большое Ондорово",
    "Большое Поле",
    "Большой Двор",
    "Борисова Грива",
    "Боровое",
    "Бугры",
    "Будогощь",
    "Ваганово",
    "Важины",
    "Васкелово",
    "Васьково",
    "Веймарн",
    "Великий Двор",
    "Верево",
    "Вещево",
    "Виллози",
    "Винницы",
    "Вистино",
    "Владимировка",
    "Воейково",
    "Вознесенье",
    "Возрождение",
    "Войсковицы",
    "Войскорово",
    "Володарское",
    "Волосово",
    "Волочаевка",
    "Волошово",
    "Волхов",
    "Вруда",
    "Всеволожск",
    "Выборг",
    "Вырица",
    "Выскатка",
    "Высоцк",
    "Гаврилово",
    "Ганьково",
    "Гарболово",
    "Гвардейское",
    "Гимрека",
    "Гладкое",
    "Глажево",
    "Глебычево",
    "Глобицы",
    "Голубково",
    "Гончарово",
    "Горбунки",
    "Горка",
    "Городец",
    "Городище",
    "Городок",
    "Горьковское",
    "Гостилицы",
    "Гостинополье",
    "Гремячево",
    "Григино",
    "Громово",
    "Дивенская",
    "Доможирово",
    "Дружная Горка",
    "Дубровка",
    "Дятлово",
    "Елизаветино",
    "Ермилово",
    "Ефимовский",
    "Ефремково",
    "Жемчужина",
    "Живой Ручей",
    "Житково",
    "Журавлево",
    "Забелино",
    "Заборье",
    "Заголодно",
    "Загривье",
    "Загубье",
    "Зайцево",
    "Заклинье",
    "Запорожское",
    "Заручье",
    "Захонье",
    "Зеленец",
    "Зеленый Холм",
    "Зимитицы",
    "Ивангород",
    "Ивановское",
    "Игнатовское",
    "Извара",
    "Ильжо",
    "Ильичево",
    "Имоченицы",
    "Исаково",
    "Иссад",
    "Казыченская",
    "Калитино",
    "Каменногорск",
    "Камышевка",
    "Кармановская",
    "Карташевская",
    "Касколовка",
    "Керстово",
    "Кикерино",
    "Кингисепп",
    "Кингисеппский",
    "Кипень",
    "Кипрушино",
    "Кирилловское",
    "Кириши",
    "Кировск",
    "Кирпичное",
    "Кирьямо",
    "Кисельня",
    "Климово",
    "Клопицы",
    "Кобона",
    "Кобралово",
    "Кобринское",
    "Коваши",
    "Колбеки",
    "Коли",
    "Колтуши",
    "Колчаново",
    "Коммунар",
    "Коммунары",
    "Комсомолец",
    "Кондратьево",
    "Копорье",
    "Корбеничи",
    "Коркино",
    "Коробицыно",
    "Коськово",
    "Котельский",
    "Котлы",
    "Кошкино",
    "Краколье",
    "Красава",
    "Красная Долина",
    "Красноармейское",
    "Красноозерное",
    "Красносельское",
    "Красные Горы",
    "Красный Вал",
    "Красный Маяк",
    "Красный Сокол",
    "Кривко",
    "Кузнечное",
    "Кузра",
    "Кузьмоловский",
    "Куйвози",
    "Кукуй",
    "Курба",
    "Курковицы",
    "Куровицы",
    "Кусино",
    "Лаврово",
    "Лаголово",
    "Ладожское Озеро",
    "Лампово",
    "Ларионово",
    "Ларьян",
    "Лебяжье",
    "Ленинское",
    "Лесколово",
    "Лесной",
    "Лесобиржа",
    "Лесогорский",
    "Лесозавод",
    "Липная Горка",
    "Лисино-Корпус",
    "Логи",
    "Лодейное Поле",
    "Ложголово",
    "Ломоносов",
    "Лопухинка",
    "Лосево",
    "Луга",
    "Лукаши",
    "Лукинская",
    "Любань",
    "Малое Карлино",
    "Манихино",
    "Матокса",
    "Мга",
    "Межозерный",
    "Мелегежская Горка",
    "Мельниково",
    "Мехбаза",
    "Миницкая",
    "Михалево",
    "Мичуринское",
    "Мозолево",
    "Молодцово",
    "Молосковицы",
    "Монастырек",
    "Мотохово",
    "Мошковые Поляны",
    "Мурино",
    "Мшинская",
    "Наволок",
    "Надкопанье",
    "Надпорожье",
    "Назия",
    "Нежново",
    "Нижние Осельки",
    "Низино",
    "Низовская",
    "Николаевское",
    "Николаевщина",
    "Никольский",
    "Новая",
    "Новая Ладога",
    "Новинка",
    "Ново-Девяткино",
    "Новолисино",
    "Новый Свет",
    "Нурма",
    "Овсище",
    "Овцино",
    "Озерево",
    "Озерное",
    "Окулово",
    "Оломна",
    "Ольеши",
    "Ополье",
    "Оредеж",
    "Оржицы",
    "Островно",
    "Осьмино",
    "Отрадное",
    "Павлово",
    "Паша",
    "Пашозеро",
    "Пелдуши",
    "Пельгора",
    "Пельгорторф",
    "Пеники",
    "Первомайское",
    "Перечицы",
    "Перово",
    "Пески",
    "Песочное",
    "Петровское",
    "Пехенец",
    "Печково",
    "Пирозеро",
    "Плодовое",
    "Плоское",
    "Победа",
    "Подборовье",
    "Подвязье",
    "Поддубье",
    "Подпорожье",
    "Поляны",
    "Померанье",
    "Попкова Гора",
    "Поречье",
    "Потанино",
    "Поток",
    "Починок",
    "Прибытково",
    "Приветнинское",
    "Приладожский",
    "Приморск",
    "Приозерск",
    "Пруды",
    "Пудомяги",
    "Пудость",
    "Путилово",
    "Пушное",
    "Пчева",
    "Пчевжа",
    "Пяхта",
    "Рабитицы",
    "Радогощь",
    "Радофинниково",
    "Разбегаево",
    "Раздолье",
    "Разметелево",
    "Раковно",
    "Рапполово",
    "Рассвет",
    "Ратница",
    "Рахья",
    "Ребовичи",
    "Рель",
    "Реполка",
    "Ретюнь",
    "Решетниково",
    "Рождествено",
    "Романовка",
    "Романовка",
    "Ромашки",
    "Ропша",
    "Рощино",
    "Русско-Высоцкое",
    "Рыбежно",
    "Рябово",
    "Сабск",
    "Санкт-Петербург",
    "Саперное",
    "Сарка",
    "Сарожа",
    "Светогорск",
    "Свирица",
    "Свирьстрой",
    "Свободное",
    "Севостьяново",
    "Сегла",
    "Селезнево",
    "Селиваново",
    "Сельхозтехника",
    "Сельцо",
    "Семиозерье",
    "Семрино",
    "Серебрянка",
    "Сертолово",
    "Сиверский",
    "Сидорово",
    "Синявино",
    "Скреблово",
    "Сланцы",
    "Слудицы",
    "Соболевщина",
    "Советский",
    "Совхозный",
    "Соколинское",
    "Сологубовка",
    "Сомино",
    "Сорзуй",
    "Сосново",
    "Сосновый Бор",
    "Спирово",
    "Спутник",
    "Среднее Село",
    "Старая Ладога",
    "Старая Малукса",
    "Старая Слобода",
    "Старополье",
    "Старосиверская",
    "Стеклянный",
    "Суйда",
    "Сумино",
    "Сусанино",
    "Суходолье",
    "Сухое",
    "Сяськелево",
    "Сясьстрой",
    "Тайцы",
    "Тарасово",
    "Тельман",
    "Тервеничи",
    "Терволово",
    "Терпилицы",
    "Тесово",
    "Тихвин",
    "Тихорицы",
    "Токарево",
    "Токари",
    "Токсово",
    "Толмачево",
    "Торковичи",
    "Торосово",
    "Торошковичи",
    "Тосно",
    "Труфаново",
    "Тургошь",
    "Тушемля",
    "Ульяновка",
    "Усадище",
    "Усть-Луга",
    "Утишье",
    "Ушаки",
    "Ущевицы",
    "Фалилеево",
    "Федоровское",
    "Форносово",
    "Фосфорит",
    "Хаппо-Ое",
    "Хвалово",
    "Хотнежа",
    "Цвелодубово",
    "Цвылево",
    "Часовенское",
    "Чаща",
    "Чемихино",
    "Черкасово",
    "Черная Речка",
    "Черновское",
    "Чолово",
    "Шалово",
    "Шамокша",
    "Шапки",
    "Шапша",
    "Шархиничи",
    "Шеменичи",
    "Шепелево",
    "Шлиссельбург",
    "Шпаньково",
    "Шум",
    "Щеглово-Совхоз",
    "Щугозеро",
    "Юкки",
    "Яблоницы",
    "Яльгелево",
    "Ям-Тесово",
    "Янега",
    "Яровщина",
    "Ярославичи"
};

#endif // DEFINES_H
