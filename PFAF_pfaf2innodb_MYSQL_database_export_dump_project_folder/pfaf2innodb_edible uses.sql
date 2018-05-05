CREATE DATABASE  IF NOT EXISTS `pfaf2innodb` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */;
USE `pfaf2innodb`;
-- MySQL dump 10.13  Distrib 8.0.11, for Win64 (x86_64)
--
-- Host: localhost    Database: pfaf2innodb
-- ------------------------------------------------------
-- Server version	8.0.11

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
 SET NAMES utf8 ;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `edible uses`
--

DROP TABLE IF EXISTS `edible uses`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `edible uses` (
  `Use` varchar(25) NOT NULL,
  `Catagory` varchar(15) DEFAULT NULL,
  `Description` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`Use`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `edible uses`
--

LOCK TABLES `edible uses` WRITE;
/*!40000 ALTER TABLE `edible uses` DISABLE KEYS */;
INSERT INTO `edible uses` (`Use`, `Catagory`, `Description`) VALUES ('Chocolate','Edible','substitutes for chocolate, that is.'),('Coffee','Edible','the various substitutes that can be used instead of coffee.'),('Colouring','Edible','edible dyes'),('Condiment','Edible','the various plants that are used as flavourings, either as herbs, spices or condiments.'),('Curdling agent','Edible','used to curdle soya milk in making cheese.'),('Drink','Edible','not including plant saps, tea or coffee substitutes.'),('Egg','Edible','Substitutes for eggs.'),('Flowers','Edible',NULL),('Fruit','Edible',NULL),('Gelatine','Edible','substitutes that is.'),('Gum','Edible','can be chewed as a chewing gum or can often be used as a sweetener or thickening agent in foods.'),('Inner bark','Edible','the bark that is found just beneath the tough outer bark of trees and shrubs.'),('Leaves','Edible',NULL),('Manna','Edible','this is a sweet substance that exudes naturally from certain plants, usually from the stems.'),('Milk','Edible','made from plants, that is.'),('Nectar','Edible','produced in such abundance by some flowers that it can be harvested fairly easily.'),('Oil','Edible',NULL),('Pectin','Edible','a substance that is used to thicken jams etc and as a culture medium in laboratories.'),('Pollen','Edible',NULL),('Root','Edible','includes bulbs, corms, tubers, rhizomes etc.'),('Rutin','Edible','often used as a food supplement.'),('Salt','Edible','plants that provide a substitute for salt.'),('Sap','Edible','usually of trees and usually but not always used as a drink.'),('Seed','Edible','includes nuts, cereals, peas and beans.'),('Seedpod','Edible','things such as Okra, French and Runner beans.'),('Stabilizer','Edible','this is often a gum and could perhaps be included there.'),('Stem','Edible','this often intergrades into leaves.'),('Sweetener','Edible','includes sugar substitutes.'),('Tea','Edible','the various herb teas that can be used in place of tea, plus the genuine article.');
/*!40000 ALTER TABLE `edible uses` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-05-05 16:36:54
