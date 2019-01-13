-- phpMyAdmin SQL Dump
-- version 3.5.1
-- http://www.phpmyadmin.net
--
-- Хост: 127.0.0.1
-- Время создания: Янв 13 2019 г., 23:39
-- Версия сервера: 5.5.25
-- Версия PHP: 5.3.13

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- База данных: `cpluscource`
--

-- --------------------------------------------------------

--
-- Структура таблицы `analyzes`
--

CREATE TABLE IF NOT EXISTS `analyzes` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `login` varchar(40) NOT NULL,
  `type` varchar(40) NOT NULL,
  `date` date NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=2 ;

--
-- Дамп данных таблицы `analyzes`
--

INSERT INTO `analyzes` (`id`, `login`, `type`, `date`) VALUES
(1, 'user1', 'Кровь', '2019-01-14');

-- --------------------------------------------------------

--
-- Структура таблицы `analyze_type`
--

CREATE TABLE IF NOT EXISTS `analyze_type` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `type` varchar(40) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=3 ;

--
-- Дамп данных таблицы `analyze_type`
--

INSERT INTO `analyze_type` (`id`, `type`) VALUES
(1, 'Кровь'),
(2, 'Слюна');

-- --------------------------------------------------------

--
-- Структура таблицы `doctors`
--

CREATE TABLE IF NOT EXISTS `doctors` (
  `doctor_id` int(11) NOT NULL AUTO_INCREMENT,
  `login` text NOT NULL,
  `doctor_fio` varchar(40) NOT NULL,
  `doctor_profession` varchar(40) NOT NULL,
  PRIMARY KEY (`doctor_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=9 ;

--
-- Дамп данных таблицы `doctors`
--

INSERT INTO `doctors` (`doctor_id`, `login`, `doctor_fio`, `doctor_profession`) VALUES
(3, '', 'Андреев Дмитрий Александрович', 'Лучший врач'),
(4, '', 'Порфирьев Александр Отчество', 'Мужской генеколог'),
(5, '', 'Михеев Михаил Отчетво', 'Акушер'),
(6, '', 'Фантров Алексей Отчество', 'Мужской генеколог'),
(8, 'doctor1', 'Егор Егорович Егоров', 'Лучший врач');

-- --------------------------------------------------------

--
-- Структура таблицы `professions`
--

CREATE TABLE IF NOT EXISTS `professions` (
  `profession_id` int(11) NOT NULL AUTO_INCREMENT,
  `profession` varchar(40) NOT NULL,
  PRIMARY KEY (`profession_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=5 ;

--
-- Дамп данных таблицы `professions`
--

INSERT INTO `professions` (`profession_id`, `profession`) VALUES
(1, 'Лучший врач'),
(2, 'Мужской генеколог'),
(3, 'Терапевт'),
(4, 'Акушер');

-- --------------------------------------------------------

--
-- Структура таблицы `records`
--

CREATE TABLE IF NOT EXISTS `records` (
  `record_id` int(11) NOT NULL AUTO_INCREMENT,
  `user` varchar(40) NOT NULL,
  `doctor_name` varchar(40) NOT NULL,
  `record_date` date NOT NULL,
  `record_time` varchar(6) NOT NULL,
  PRIMARY KEY (`record_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=8 ;

--
-- Дамп данных таблицы `records`
--

INSERT INTO `records` (`record_id`, `user`, `doctor_name`, `record_date`, `record_time`) VALUES
(1, '', '3', '2018-12-27', '6:00'),
(2, '', '3', '2018-12-27', '6:30'),
(3, '', 'Андреев Дмитрий Александрович', '2018-12-27', '7:00'),
(4, '', 'Порфирьев Александр Отчество', '2018-12-27', '7:30'),
(7, 'admin', 'Андреев Дмитрий Александрович', '2018-12-28', '6:00');

-- --------------------------------------------------------

--
-- Структура таблицы `test`
--

CREATE TABLE IF NOT EXISTS `test` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `data` varchar(40) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=6 ;

--
-- Дамп данных таблицы `test`
--

INSERT INTO `test` (`id`, `data`) VALUES
(1, 'data'),
(2, 'data'),
(3, 'data'),
(4, 'data'),
(5, 'data');

-- --------------------------------------------------------

--
-- Структура таблицы `users`
--

CREATE TABLE IF NOT EXISTS `users` (
  `user_id` int(11) NOT NULL AUTO_INCREMENT,
  `user_login` varchar(40) NOT NULL,
  `user_password` varchar(40) NOT NULL,
  `user_role` varchar(40) NOT NULL,
  `phone` text NOT NULL,
  `adress` text NOT NULL,
  PRIMARY KEY (`user_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=8 ;

--
-- Дамп данных таблицы `users`
--

INSERT INTO `users` (`user_id`, `user_login`, `user_password`, `user_role`, `phone`, `adress`) VALUES
(1, 'admin', '202cb962ac59075b964b07152d234b70', 'admin', '', ''),
(2, 'simple_user', '202cb962ac59075b964b07152d234b70', 'user', '', ''),
(3, 'newuser', '202cb962ac59075b964b07152d234b70', '', '', ''),
(4, 'user1', '202cb962ac59075b964b07152d234b70', 'user', '', ''),
(5, 'user2', '202cb962ac59075b964b07152d234b70', 'user', '893123456', 'ул. Медведева'),
(7, 'doctor1', '202cb962ac59075b964b07152d234b70', 'doctor', '8923423424', 'Ул.Мира');

-- --------------------------------------------------------

--
-- Структура таблицы `user_card`
--

CREATE TABLE IF NOT EXISTS `user_card` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `user_login` varchar(40) NOT NULL,
  `diagnosis` varchar(100) NOT NULL,
  `prescription` varchar(500) NOT NULL,
  `data` date NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=2 ;

--
-- Дамп данных таблицы `user_card`
--

INSERT INTO `user_card` (`id`, `user_login`, `diagnosis`, `prescription`, `data`) VALUES
(1, 'user1', 'Грипп', 'Что-то пить', '2019-01-13');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
