-- phpMyAdmin SQL Dump
-- version 3.5.1
-- http://www.phpmyadmin.net
--
-- Хост: 127.0.0.1
-- Время создания: Дек 27 2018 г., 13:23
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
-- Структура таблицы `doctors`
--

CREATE TABLE IF NOT EXISTS `doctors` (
  `doctor_id` int(11) NOT NULL AUTO_INCREMENT,
  `doctor_fio` varchar(40) NOT NULL,
  `doctor_profession` varchar(40) NOT NULL,
  PRIMARY KEY (`doctor_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=7 ;

--
-- Дамп данных таблицы `doctors`
--

INSERT INTO `doctors` (`doctor_id`, `doctor_fio`, `doctor_profession`) VALUES
(3, 'Андреев Дмитрий Александрович', 'Лучший врач'),
(4, 'Порфирьев Александр Отчество', 'Мужской генеколог'),
(5, 'Михеев Михаил Отчетво', 'Акушер'),
(6, 'Фантров Алексей Отчество', 'Мужской генеколог');

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
  PRIMARY KEY (`user_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=4 ;

--
-- Дамп данных таблицы `users`
--

INSERT INTO `users` (`user_id`, `user_login`, `user_password`, `user_role`) VALUES
(1, 'admin', '202cb962ac59075b964b07152d234b70', 'admin'),
(2, 'simple_user', '202cb962ac59075b964b07152d234b70', 'user'),
(3, 'newuser', '202cb962ac59075b964b07152d234b70', '');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
