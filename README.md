# TheProblemOfDiningCryptographers
Проект по курсу "Защита информации"
![](MIPT_logo.png)

В данном репозитории ещё не реализовано решение задачи "Проблема обедающих криптографов".
Полное описание "проблемы" и ее решения можно найти [здесь](https://ru.wikipedia.org/wiki/%D0%9F%D1%80%D0%BE%D0%B1%D0%BB%D0%B5%D0%BC%D0%B0_%D0%BE%D0%B1%D0%B5%D0%B4%D0%B0%D1%8E%D1%89%D0%B8%D1%85_%D0%BA%D1%80%D0%B8%D0%BF%D1%82%D0%BE%D0%B3%D1%80%D0%B0%D1%84%D0%BE%D0%B2#%D0%90%D0%BB%D1%8C%D1%82%D0%B5%D1%80%D0%BD%D0%B0%D1%82%D0%B8%D0%B2%D0%BD%D1%8B%D0%B5_%D0%B0%D0%BB%D1%84%D0%B0%D0%B2%D0%B8%D1%82%D1%8B_%D0%B8_%D0%BE%D0%BF%D0%B5%D1%80%D0%B0%D1%82%D0%BE%D1%80%D1%8B).

Проект состоит из двух частей:
* Протокол выявления ответа на вопрос "заплатило ли Агентство Национальной Безопасности" состоящий из [клиентной](Cpp_clients/DiningClient) и [серверной](Py_server/DiningServer) частей.
По сути это анонимная рассылка одного бита. Условие рассылки - только один клиент указывает, что "оплатил счет за всех", либо "не платил" никто. Сервер прекращает свою работу как только, необходимое количество клиентов вступит в протокол. 
(Сервер рассылает всем клиентам карту IP адресов с указанием номера каждого клиента в протоколе). Таким образом, сам сервер не участвует в пересылках, что означает, что протокол реализова как  peer-to-peer рассылка одного бита.

* Протокол анонимной рассылки двух-битных слов любой длинны, состоящий из [клиентной](Cpp_clients/DCNetworkClient) и [серверной](Py_server/DCNetworkServer) частей.
Нет никаки условий рассылки. Задача сервера - сгенерировать карту адрессов и снабдить всех клиентов этой картой, обработать все запросы на вещание и выдать всем случайные номера в очереди вещания, разослать количество слов, отправляемых по протоколу.
Сервер также прекращает работу, как только снабдит всех клиентов необходимой для проктокола информацией. Таким образом, он по прежнему не является участником протокола, что характеризует построенную нами сеть как P2P.

Запуск проекта:
* Шаг 1: Запуск сервера и клиентов;
* Шаг 2: Вызвать окно "Settings of Protocol", нажатием на одноименную кнопку.
* Шаг 3: Заполнение информации в открывшемся окне (Необходимо указать ip-адрес сервера и заполнить поле score). Примечание: Не забудеь в файле config.yaml заменить значение напротив строки "num_of_cryptographers:" на то количество людей, которые хотят участвовать в протоколе;
* Шаг 4: [ОПЦИОНАЛЬНО]: Если, вы реализуете "Протокол анонимной рассылки двух-битных слов любой длинны", и хотите передать слово, нужно заполнить окошко словом, которое вы хотите пересеылать, которое автоматическе возникнет после нажатия кнопки "apply"
* Шаг 5: Созерцайте.

Тестирование:
В папке находится xlsx файл с названием test_list. В нем описаны все проводимые тесты с проэктом протокола анонимной рассылки двух-битных слов.
* Подстветка зеленым фоном - тест успешно пройден.
* Стобик "Комп" <=> копьютер на котором запускался протокол (был в веден с целью развеять наши сомнения по поводу того, что все компьютеры корректно выполняют пересылки по сокетам в момент отладки кода). 
* Столбики "Номер за столом" и "Номер ещания" ровно то, что написано в названиях этих столбиков согласно протоколу. 