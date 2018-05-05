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
-- Table structure for table `composition`
--

DROP TABLE IF EXISTS `composition`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `composition` (
  `Latin Name` varchar(60) NOT NULL,
  `Common Name` varchar(50) DEFAULT NULL,
  `Part of plant` varchar(15) NOT NULL,
  `Dry or Fresh weight` varchar(1) NOT NULL,
  `Water` float DEFAULT NULL,
  `Calories` float DEFAULT NULL,
  `Protein` float DEFAULT NULL,
  `Fat` float DEFAULT NULL,
  `Carbohydrate` float DEFAULT NULL,
  `Fibre` float DEFAULT NULL,
  `Ash` float DEFAULT NULL,
  `Calcium` float DEFAULT NULL,
  `Phosphorus` float DEFAULT NULL,
  `Iron` float DEFAULT NULL,
  `Magnesium` float DEFAULT NULL,
  `Sodium` float DEFAULT NULL,
  `Potassium` float DEFAULT NULL,
  `Zinc` float DEFAULT NULL,
  `VitaminA` float DEFAULT NULL,
  `Thiamine` float DEFAULT NULL,
  `Riboflavin` float DEFAULT NULL,
  `Niacin` float DEFAULT NULL,
  `VitaminC` float DEFAULT NULL,
  `VitaminB6` float DEFAULT NULL,
  `Source` varchar(15) DEFAULT NULL,
  `Notes` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`Latin Name`,`Part of plant`),
  KEY `Common Name` (`Common Name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `composition`
--

LOCK TABLES `composition` WRITE;
/*!40000 ALTER TABLE `composition` DISABLE KEYS */;
INSERT INTO `composition` (`Latin Name`, `Common Name`, `Part of plant`, `Dry or Fresh weight`, `Water`, `Calories`, `Protein`, `Fat`, `Carbohydrate`, `Fibre`, `Ash`, `Calcium`, `Phosphorus`, `Iron`, `Magnesium`, `Sodium`, `Potassium`, `Zinc`, `VitaminA`, `Thiamine`, `Riboflavin`, `Niacin`, `VitaminC`, `VitaminB6`, `Source`, `Notes`) VALUES ('Abutilon theophrasti','China jute','Seed','F',NULL,NULL,17.4,16,33.8,NULL,4.4,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Acacia coriacea','Wiry wattle','Seed','F',NULL,NULL,20,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Aesculus californica','Californian buckeye','Seed','F',NULL,NULL,23,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Allium cepa ascalonicum','Shallots','Root','F',79.8,72,2.5,0.1,16.8,0.7,0.8,37,60,1.2,NULL,12,334,NULL,0,0.06,0.02,0.2,8,NULL,'218',NULL),('Allium chinense','Rakkyo','Root','F',NULL,NULL,3.1,0.1,18.3,NULL,0.7,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Allium fistulosum','Welsh onion','Leaves','F',NULL,NULL,1.4,0.3,4.6,NULL,0.8,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Allium fistulosum','Welsh onion','Root','D',0,349,18.6,3.5,70.9,9.3,7,640,477,13,NULL,174,2233,NULL,7326,0.7,0.93,5.81,221,NULL,'218',NULL),('Allium sativum','Garlic','Root','D',0,360,13.5,0.7,82,3,3.5,65,400,4.3,NULL,53,1250,NULL,0,0.7,0.2,1.25,35,NULL,'218','The figures given here are the median of a range given in the report.'),('Allium schoenoprasum','Chives','Leaves','D',0,330,27,5.5,60,10.7,7,900,509,15,NULL,NULL,2874,NULL,40000,1.1,1.15,6,522,NULL,'218','The figures given here are the median figures of a range that was quoted in the report.'),('Allium tuberosum','Garlic chives','Leaves','F',NULL,NULL,2.6,0.6,2.4,NULL,0.9,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Amaranthus blitum',NULL,'Leaves','F',NULL,NULL,3.9,1.1,9.4,NULL,3.2,323,NULL,8.3,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Amaranthus caudatus','Love lies bleeding','Seed','F',NULL,NULL,18,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Amaranthus cruentus',NULL,'Seed','F',NULL,NULL,15,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Amaranthus spinosus',NULL,'Leaves','D',0,276,30,4.5,50,10,20,5000,450,100,NULL,30,3000,NULL,40,0.06,2.02,8,503,NULL,NULL,NULL),('Amaranthus tricolor',NULL,'Leaves','D',0,NULL,NULL,NULL,NULL,NULL,NULL,2441,1008,51,NULL,34,4475,NULL,37623,0.68,2.37,11.5,730,NULL,NULL,NULL),('Amaranthus viridis','Calalu','Leaves','D',0,283,34.2,5.3,44.1,6.6,16.4,2243,500,27,NULL,336,2910,NULL,50,0.07,2.43,11.8,790,NULL,NULL,NULL),('Amorphophallus rivieri','Devil\'s tongue','Leaves','D',0,308,3.8,0,88.5,3.8,7.7,654,269,11.5,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Amorphophallus rivieri','Devil\'s tongue','Root','F',97.4,8,0.1,0,2.3,0.1,0.2,17,7,0.3,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Amphicarpaea pitcheri','Hog peanut','Seed','F',NULL,NULL,25,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Anethum graveolens','Dill','Leaves','F',7.2,253,20,4.4,55.8,11.9,12.6,1784,543,48.8,451,208,3308,3.3,NULL,0.42,0.28,2.8,NULL,1.5,NULL,NULL),('Anethum graveolens','Dill','Seed','F',7.7,305,NULL,14.5,55.2,21.1,6.7,1516,277,16.3,256,20,1186,5.2,53,0.42,0.28,NULL,NULL,NULL,NULL,NULL),('Apios americana','Ground nut','Root','F',NULL,NULL,17,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Apios fortunei',NULL,'Root','F',NULL,NULL,4.2,0.2,24.3,NULL,1.3,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Arachis hypogaea','Peanut','Seed','F',13,500,29,45,15,2.7,2.5,49,409,3.8,NULL,NULL,NULL,NULL,15,0.79,0.14,15.5,1,NULL,'218','The figures given here are the median figures of those quoted in the report.'),('Aralia cordata','Udo','Shoots','F',NULL,NULL,1.1,0.42,0.8,NULL,0.55,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Arctium lappa','Great burdock','Leaves','F',NULL,NULL,3.5,1.8,19.4,NULL,8.8,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Arctium lappa','Great burdock','Root','F',NULL,NULL,2.5,0.14,14.5,NULL,1.17,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Artemisia keiskeana',NULL,'Leaves','F',NULL,NULL,5.6,1.2,9.5,NULL,2.6,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Asparagus officinalis','Asparagus','Stem','F',91.7,26,2.5,0.2,5,0.7,0.6,22,62,1,NULL,2,278,NULL,540,0.18,0.2,1.5,33,NULL,'218',NULL),('Aster amellus',NULL,'Leaves','D',0,305,32.8,5.5,50,8.6,11.7,328,594,31,NULL,NULL,4164,NULL,26,1.41,2.81,8.59,688,NULL,NULL,NULL),('Basella alba','Indian spinach','Leaves','D',0,275,20,3.5,54,9,19,3000,NULL,NULL,NULL,NULL,NULL,NULL,50,0.7,1.8,7.5,1200,NULL,NULL,NULL),('Bassia scoparia','Summer cypress','Leaves','D',0,NULL,21.5,2.4,56.8,19.7,19.2,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218',NULL),('Bassia scoparia','Summer cypress','Seed','D',0,NULL,24,12.4,NULL,NULL,6.4,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218','The values here are based on the median figures of those quoted in the report.'),('Benincasa hispida','Wax gourd','Fruit','F',96.1,13,0.4,0.2,3,0.5,0.3,19,19,0.4,NULL,6,111,NULL,NULL,4,0.11,0.4,13,NULL,'218',NULL),('Berberis aristata','Chitra','Fruit','F',NULL,NULL,2.3,NULL,12,NULL,2,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Beta vulgaris craca','Beetroot','Leaves','F',86.4,45,3.2,0.4,8.1,3.8,1.9,114,34,3.1,NULL,NULL,NULL,NULL,3152,0.07,0.22,0.6,50,NULL,'218','The figures for Vitamin a are said to be milligrammes.'),('Bidens pilosa','Beggar\'s ticks','Leaves','D',0,295,24.5,4,56.4,12.1,15.1,1721,273,NULL,NULL,11,267,NULL,12,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Bidens pilosa','Beggar\'s ticks','Seed','F',NULL,NULL,17.5,17.1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Brachychiton populneus','Kurrajong','Seed','F',NULL,NULL,18,25,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Brasenia schreberi','Water shield','Leaves','D',0,135,9.5,2.7,24.3,1.4,63.5,122,311,27,NULL,NULL,NULL,NULL,135,0.41,NULL,0.05,0,NULL,'218','The figure for ash is remarkably high and needs to be verified.'),('Brassica juncea','Chinese mustard','Seed','F',NULL,NULL,NULL,30,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Brassica oleracea gongylodes','Kohl rabi','Leaves','D',0,320,23.5,2.5,62.5,13,10.5,430,450,10.5,NULL,80,3100,NULL,15000,0.6,0.7,4.5,670,NULL,'218','The figures given here are the median of a range that was given in the reference.'),('Brassica oleracea gongylodes','Kohl rabi','Stem','F',90.3,29,2,0.1,6.6,1,1,41,51,0.5,NULL,8,372,NULL,20,0.06,0.04,0.3,66,NULL,'218',NULL),('Brassica rapa','Turnip','Leaves','D',0,2300,30,4,54,7,12,1600,1000,17,NULL,NULL,4500,NULL,NULL,30,2,8,500,NULL,'218',NULL),('Brassica rapa','Turnip','Root','D',0,323,15.4,0,72.8,13.8,12.3,585,646,7.7,NULL,NULL,NULL,NULL,NULL,0.46,0.77,NULL,1154,NULL,'218',NULL),('Brassica rapa','Turnip','Seed','D',0,450,24,20,50,17,NULL,NULL,NULL,6.9,NULL,NULL,NULL,NULL,NULL,0.58,0.43,NULL,NULL,NULL,'218',NULL),('Brassica rapa chinensis','Pak choi','Leaves','D',0,350,NULL,NULL,25,14,12,1700,500,28,NULL,420,5100,NULL,25000,0.6,1.3,42,700,NULL,'218','The figures given here are median figures from a fairly wide range that was given in the report.'),('Brassica rapa pekinensis','Chinese cabbage','Leaves','D',0,236,23.6,3.6,41.8,16.4,30.9,636,709,9.1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218',NULL),('Camellia sinensis','Tea plant','Leaves','D',0,NULL,25.7,6.5,40.8,NULL,5,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Canna edulis','Achira','Leaves','F',NULL,NULL,10,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Canna edulis','Achira','Root','D',0,NULL,3,NULL,80,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Cannabis sativa','Hemp','Seed','D',0,487,31.4,29.6,31.9,23.5,7.1,139,1123,13.9,NULL,NULL,NULL,NULL,518,0.37,0.2,2.43,0,NULL,'218',NULL),('Capsella bursa-pastoris','Shepherd\'s purse','Leaves','D',0,280,35.6,4.2,44.1,10.2,16.1,1763,729,40.7,NULL,NULL,3939,NULL,21949,2.12,1.44,3.4,305,NULL,'218',NULL),('Capsella bursa-pastoris','Shepherd\'s purse','Seed','F',NULL,NULL,NULL,35,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Carum carvi','Caraway','Leaf','F',7.2,253,20,4.4,55.8,11.9,12.6,1784,543,48.8,451,208,3308,3.3,NULL,0.42,0.28,2.8,NULL,1.5,NULL,NULL),('Carum carvi','Caraway','Seed','F',9.9,333,19.8,14.6,49.9,12.6,5.9,689,568,16.2,258,17,1351,5.5,363,0.38,0.38,3.6,NULL,NULL,NULL,NULL),('Castanea mollissima','Chinese chestnut','Seed','D',0,403,11.9,2.7,83.2,2.2,NULL,36,NULL,NULL,NULL,NULL,NULL,NULL,168,0.29,0.32,1.44,65,NULL,'218',NULL),('Chenopodium album','Fat hen','Leaves','D',0,260,24,5,45,15,28,2300,500,25,NULL,NULL,NULL,NULL,31583,0.67,1.58,2.5,NULL,NULL,'218','The figures are the median of a range given in the report.'),('Chenopodium album','Fat hen','Seed','D',0,NULL,18,8,69,20,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218','The figures are the median of a range given in the report.'),('Chrysanthemum coronarium','Chop suey greens','Leaves','D',0,292,27.7,4.6,50.8,13.8,16.9,969,523,38.5,NULL,1631,3938,NULL,49,1.38,2.92,9.23,415,NULL,NULL,NULL),('Cichorium intybus','Chicory','Leaves','D',0,290,24.6,2.9,59.4,13,13,1145,NULL,24.6,NULL,NULL,NULL,NULL,23,1.01,1.74,5.8,159,NULL,NULL,NULL),('Cichorium intybus','Chicory','Root','F',77,NULL,NULL,0.6,NULL,NULL,0.8,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Citrullus lanatus','Water melon','Fruit','D',0,344,7.8,1.6,85.9,6.3,4.7,125,141,4.7,NULL,NULL,1351,NULL,4300,0.5,0.6,NULL,NULL,NULL,'218',NULL),('Citrullus lanatus','Water melon','Seed','D',0,559,19.8,41.7,34.5,24.2,3.9,129,831,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218',NULL),('Citrus limon','Lemon','Fruit','F',90,28,0.8,0.5,8.2,0.6,5.4,33,15,0.5,NULL,3,137,NULL,12,0.5,0.02,0.1,52,NULL,'218','The figures given here are the median of a range given in the report.'),('Codonopsis lanceolata',NULL,'Leaves','D',0,416,12.9,19.7,61.2,36,6.2,506,680,11.8,NULL,NULL,NULL,NULL,0,0.67,1.24,4.5,0,NULL,'218',NULL),('Coix lacryma-jobi','Job\'s tears','Seed','F',11.2,380,15.4,6.2,65.3,0.8,1.9,25,435,5,NULL,NULL,NULL,NULL,0,0.28,0.19,4.3,0,NULL,'218',NULL),('Conyza canadensis','Canada fleabane','Leaves','D',0,NULL,14.9,1.8,75.1,26.1,8.2,1010,280,NULL,NULL,NULL,2610,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Corylus avellana','Hazel','Seed','D',0,650,16,60,20,4,2.8,250,400,4,NULL,2.1,900,NULL,NULL,0.3,0.5,5.3,6,NULL,NULL,NULL),('Crataegus pinnatifida',NULL,'Fruit','D',0,352,1.5,3.8,91.6,6.9,3.1,326,96,8,NULL,NULL,1253,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218',NULL),('Cucurbita pepo','Marrow','Flowers','D',0,308,26.9,5.8,51.9,11.5,15.4,904,1653,19.2,NULL,NULL,NULL,NULL,7692,0.38,2.12,11.54,346,NULL,'218',NULL),('Cucurbita pepo','Marrow','Fruit','D',0,333,8.6,2.5,81.5,9.9,7.4,296,407,8.6,NULL,99,4321,NULL,9691,0.37,0.49,6.2,173,NULL,'218',NULL),('Cucurbita pepo','Marrow','Leaves','D',0,271,43.8,4.2,35.4,15.6,16.7,1323,1000,60.4,NULL,NULL,NULL,NULL,16979,1.5,1.8,18.8,604,NULL,'218',NULL),('Cucurbita pepo','Marrow','Seed','D',0,578,30.3,48.8,15.7,2,5.1,53,1197,12,NULL,NULL,NULL,NULL,44,0.2,0.2,2.5,NULL,NULL,'218',NULL),('Cydonia oblonga','Quince','Fruit','D',0,355,2.7,1.2,94,14,2.5,55,95,4.3,NULL,25,1216,NULL,130,0.15,0.18,1.8,95,NULL,'218','The figures given here are the median of a range given in the report.'),('Descurainia sophia','Flixweed','Seed','D',0,NULL,27.5,33,NULL,NULL,3.7,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218','The figures given here are median figures of a range that was given in the report.'),('Diospyros kaki','Persimmon','Fruit','D',0,350,3.6,1.5,91,7.7,4,80,100,8,NULL,20,950,NULL,5600,0.2,0.15,0.9,75,NULL,'218',NULL),('Draba nemerosa',NULL,'Leaves','D',0,NULL,15.8,2.1,67.7,17.6,14.4,3310,330,NULL,NULL,NULL,1780,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218','It is assumed that this analysis is for the leaves on a zero moisture basis, though the report was a bit vague.'),('Echinochloa crus-galli','Barnyard millet','Leaves','D',0,NULL,7.4,2.9,81.1,31.3,8.6,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218',NULL),('Elaeagnus pungens',NULL,'Seed','D',0,NULL,42.2,23.1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218',NULL),('Eleocharis dulcis','Chinese water chestnut','Root','D',NULL,360,8,1.2,86,3.5,5.5,22,350,3.5,NULL,70,2450,NULL,0,0.4,0.5,5,25,NULL,'218',NULL),('Eleusine coracana','Finger millet','Seed','D',0,370,7.6,1.5,88,3,2.7,410,290,12.6,NULL,NULL,NULL,NULL,0.48,0.33,0.11,1.2,0,NULL,'218','The figures given here are the median of a range given in the report.'),('Emilia sonchifolia',NULL,'Leaves','D',0,308,22,3.3,64.3,11,10.4,2187,648,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),('Eriobotrya japonica','Loquat','Fruit','D',0,360,3.6,3.2,90,5.8,4,290,190,4.3,NULL,35,2650,NULL,5000,0.18,4.9,2.3,7.84,NULL,'218','The figures given are the median of a range quoted in the report.'),('Euryale ferox',NULL,'Seed','D',0,400,10.3,0.2,89,0.2,0.6,34,100,1.5,NULL,NULL,66,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218',NULL),('Ficus carica','Fig','Fruit','D',0,352,6,1.2,89,7,3.8,220,133,2.7,NULL,9,862,NULL,347,0.25,0.25,2,9.22,NULL,'218',NULL),('Fortunella margarita','Oval kumquat','Fruit','D',0,356,5.2,2.5,89,10,3.3,240,300,5.5,NULL,835,1172,NULL,1000,0.74,0.4,4.2,305,NULL,'218','The figures given here are the median of a range given in the report.'),('Ginkgo biloba','Maidenhair tree','Seed','D',0,403,10.4,3.3,83,1.3,3.5,11,327,2.6,NULL,15,1139,NULL,392,0.52,0.26,6.1,54,NULL,'218',NULL),('Helianthus annuus','Sunflower','Seed','F',4.8,560,24,47.3,19.4,3.8,4,120,837,7.1,NULL,30,920,NULL,30,1.96,0.23,5.4,0,NULL,NULL,NULL),('Hibiscus rosa-sinensis','Chinese hibiscus','Flowers','F',89.8,NULL,0.06,0.4,NULL,1.56,NULL,4,27,1.7,NULL,NULL,NULL,NULL,NULL,0.03,0.05,0.6,4.2,NULL,'218',NULL),('Hibiscus rosa-sinensis','Chinese hibiscus','Fruit','D',0,353,3.9,3.9,86.3,15.7,5.9,39,265,17,NULL,NULL,NULL,NULL,NULL,0.29,0.49,5.9,39,NULL,'218',NULL),('Hibiscus rosa-sinensis','Chinese hibiscus','Leaves','D',0,NULL,15.4,3.5,69.7,15.5,11.4,1670,520,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218',NULL),('Kummerowia striata',NULL,'Leaves','D',0,NULL,14.5,2.4,75,34,8.5,1090,235,32,NULL,NULL,1100,NULL,5,1,NULL,NULL,NULL,NULL,'218','The figures given here are median figures of a range quoted in the report.'),('Kummerowia striata',NULL,'Seed','D',NULL,NULL,39,6,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218','The figures given here are median figures of a range quoted in the report.'),('Lablab purpureus','Hyacinth bean','Seed','F',12.1,334,21.5,1.2,61.4,6.8,3.8,98,345,3.9,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218',NULL),('Lablab purpureus','Hyacinth bean','Seedpod','F',87.5,30,3.1,0.3,8.2,1.9,0.9,75,50,1.2,NULL,2,279,NULL,160,0.08,0.13,0.06,16,NULL,'218',NULL),('Lactuca sativa','Lettuce','Leaves','F',92.9,NULL,2.1,NULL,3,0.5,1.2,26,30,0.7,10,3,208,NULL,2200,NULL,NULL,0.4,15,NULL,NULL,NULL),('Lepidium sativum','Cress','Leaves','F',82.3,NULL,5.8,1,8.7,NULL,NULL,NULL,NULL,28.6,NULL,NULL,NULL,NULL,2970,0.11,0.17,1,87,NULL,'240',NULL),('Linum usitatissimum','Flax','Seed','F',6.5,498,19,35.5,35.4,6.8,3.5,220,415,23,NULL,NULL,NULL,NULL,0.03,0.17,0.16,1.4,NULL,NULL,'218','The figures given here are the median of a range given in the report. Iron had an especially large range, from 2.7 - 43.8.'),('Lycium chinense','Chinese boxthorn','Leaves','D',0,279,39.4,5.8,38.5,12.5,16.3,1423,414,51.9,NULL,1836,4981,NULL,43,0.77,2.98,7.69,77,NULL,'218',NULL),('Medicago lupulina','Black medick','Leaves','D',0,NULL,23.3,3.3,NULL,24.7,10.3,1330,300,NULL,450,NULL,2280,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218',NULL),('Medicago sativa','Alfalfa','Leaves','F',82.7,52,6,0.4,9.5,3.1,1.4,12,51,5.4,NULL,NULL,NULL,NULL,3410,0.13,0.14,0.5,162,NULL,'218',NULL),('Mentha spicata','Spearmint','Leaves','F',83,NULL,4.8,0.6,8,2,1.6,200,80,15.6,NULL,NULL,NULL,NULL,2700,NULL,NULL,0.4,NULL,NULL,'218',NULL),('Morus alba','White mulberry','Fruit','F',87.5,NULL,1.5,0.49,8.3,1.4,0.9,80,40,1.9,NULL,NULL,NULL,NULL,174,NULL,NULL,0.8,13,NULL,'218',NULL),('Morus alba','White mulberry','Leaves','D',NULL,NULL,23.5,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218, 269','The analysis also gives figures for various salts found in the leaves, but does not give figures for the pure minerals.'),('Nasturtium officinale','Watercress','Leaves','F',93.3,19,2.2,0.3,3,0.7,1.2,151,54,1.7,NULL,52,282,NULL,2940,0.08,0.16,0.9,79,NULL,'218',NULL),('Oenanthe javanica','Water dropwort','Leaves','D',0,298,19.9,3.2,62.8,12.8,14.9,1202,585,32,NULL,192,4713,NULL,24,0.64,2.34,10.6,149,NULL,NULL,NULL),('Origanum vulgare','Oregano','Leaves','D',7.2,306,11,10.2,64.4,15,7.2,1576,200,44,270,15,1669,4.4,6903,0.34,NULL,6.2,NULL,NULL,'218',NULL),('Papaver somniferum','Opium Poppy','Seed','F',6.8,533,18,44.7,23.7,6.3,6.8,1448,848,9.4,2.3,21,700,NULL,NULL,0.95,0.17,0.98,NULL,NULL,'269',NULL),('Petasites japonicus',NULL,'Leaves','D',0,250,19.5,2.8,52.8,19.4,25,1194,556,2.8,NULL,917,12500,NULL,278,0.56,0.56,5.56,56,NULL,NULL,NULL),('Phaseolus vulgaris','French Bean','Leaves','F',86.8,36,3.6,0.4,6.6,2.8,2.6,2.74,75,9.2,NULL,NULL,NULL,NULL,3230,0.18,0.06,1.3,110,NULL,'269',NULL),('Phaseolus vulgaris','French Bean','Pod','F',91,30,1.8,0.2,6.5,1,0.7,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'269',NULL),('Phaseolus vulgaris','French Bean','Seed','D',10,345,22.5,1.5,62,4.3,3.8,86,247,6.6,183,43.2,1160,NULL,5,0.54,0.19,2.1,3,NULL,'269','These are average figures from three different varieties of beans.'),('Phytolacca americana','Pokeweed','Shoots','D',0,274,31,4.8,44,NULL,20.2,631,524,20.2,NULL,NULL,NULL,NULL,62,0.95,3.93,14.3,1619,NULL,'218',NULL),('Pisum sativum','Pea','Green seed','F',76.5,44,6.2,0.4,16.9,2.4,0.9,32,102,1.2,NULL,6,350,NULL,405,0.28,0.11,2.8,27,NULL,'218',NULL),('Pisum sativum','Pea','Seed','F',10.9,NULL,22.9,1.4,60.7,1.4,2.7,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218',NULL),('Platycodon grandiflorus',NULL,'Root','D',0,379,3.2,1.2,93.7,11.7,2,306,249,8.2,NULL,NULL,NULL,NULL,0,0.13,0.47,10.3,0,NULL,'218',NULL),('Polygonum aviculare','Knotweed','Leaves','F',81.6,NULL,1.9,0.3,10.2,3.5,3.5,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218',NULL),('Polygonum bistorta','Bistort','Leaves','F',82.6,NULL,3,0.8,7.9,3.2,2.4,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218',NULL),('Portulaca oleracea','Purslane','Leaves','D',0,270,26,4,50,11.5,20,1500,550,29,NULL,55,1800,NULL,15000,0.35,1.4,6,250,NULL,'218','The figures given here are the median of a very wide range quoted in the report.'),('Prunus mume','Japanese apricot','Fruit','D',0,388,9.7,13.4,67.9,10.4,9,82,269,13.4,NULL,60,2328,NULL,149,0.37,0.37,3.73,75,NULL,'218',NULL),('Prunus persica','Peach','Fruit','D',0,350,5.5,1.4,90,10,4,60,135,6.5,NULL,30,1800,NULL,3000,0.15,0.25,4.7,70,NULL,'218','The figures given here are the median of a range quoted in the report.'),('Prunus persica','Peach','Seed','D',0,NULL,31.2,39.9,NULL,14.8,2.7,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218',NULL),('Pueraria montana lobata','Kudzu Vine','Root','F',68.6,113,2.1,0.1,27.8,0.7,1.4,15,18,0.6,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'269',NULL),('Punica granatum','Pomegranate','Fruit','D',0,362,5,2.2,90.5,12,2.6,40,180,3,NULL,4.35,1250,NULL,90,0.27,0.25,3.2,43,NULL,'218','The figures given here are the median of a wide range quoted in the report.'),('Raphanus sativus','Radish','Leaves','D',0,287,28.7,5.2,49.6,9.6,16.5,1913,261,35.7,NULL,956,4348,NULL,21,0.7,2.43,34.8,704,NULL,'218','Vitamin A is mg not IU'),('Robinia pseudoacacia','Black locust','Seed','D',NULL,NULL,21,3,NULL,28,6.8,1400,0.3,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218, 269',NULL),('Rumex crispus','Curled dock','Leaves','F',92.6,21,1.5,0.3,4.1,0.9,1.5,74,56,5.6,NULL,NULL,NULL,NULL,1.38,0.06,0.08,0.4,30,NULL,'218','The figure for vitamin A is in milligrammes.'),('Sanguisorba minor','Salad burnet','Leaves','D',0,NULL,11.1,2,80.4,18,6.5,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218',NULL),('Secale cereale','Rye','Seed','D',0,380,13.2,2.5,82.5,2.2,2,44,400,4,NULL,4,524,NULL,0,0.4,0.24,1.8,0,NULL,'218','The figures given here are the median of a range given in the report.'),('Sedum makinoi',NULL,'Leaves','D',0,361,13.1,16.4,55.7,29.5,14.8,3820,885,41,NULL,NULL,NULL,NULL,574,2.46,1.97,NULL,492,NULL,'218',NULL),('Setaria italica','Foxtail millet','Seed','D',0,384,10.7,3.3,84.2,1.4,1.8,37,275,6.2,NULL,8,281,NULL,0,0.48,0.14,2.48,0,NULL,'218',NULL),('Sinapis alba','White mustard','Seed','D',0,500,27.2,35,34,6,4.5,500,800,16,NULL,5,732,NULL,400,0.5,0.37,8,0,NULL,'218','These are median figures of a range given in the report.'),('Solanum nigrum','Black nightshade','Leaves','F',86.4,42,4,0.7,7.6,1.6,1.7,210,70,5,NULL,NULL,NULL,NULL,2000,0.15,0.15,1.2,43,NULL,'218','The figures given here are the median of a wide range given in the report.'),('Solanum tuberosum','Potato','Root','F',79,80,2.4,0.1,18,0.5,1.3,10,51,0.8,NULL,5,401,NULL,20,0.9,0.03,1.5,20,NULL,'269','These figures are the mean obtained from a range of readings.'),('Sonchus oleraceus','Sowthistle','Leaves','D',0,265,28,4.5,45,5.9,22,1500,500,45.6,NULL,NULL,NULL,NULL,35,1.5,5,5,60,NULL,NULL,NULL),('Sorghum bicolor','Sorghum','Seed','D',12,342,10,3.7,72.7,2.2,1.5,22,242,3.8,NULL,8,44,NULL,0,0.33,0.18,3.9,0,NULL,'269',NULL),('Spinacia oleracea','Spinach','Leaves','D',0,285,28,5.5,40,8,23,800,415,80,NULL,650,4500,NULL,50,0.7,2,8,600,NULL,'218','The values here are based on the median figures of those quoted in the report. Vitamin A figures are in milligrammes.'),('Stellaria media','Chickweed','Leaves','D',0,NULL,14.5,2.4,63.9,20.5,19.3,NULL,NULL,NULL,NULL,NULL,NULL,NULL,30,0.02,0.14,0.51,375,NULL,'218','The figure for vitamin A is in mg'),('Thlaspi arvense','Pennycress','Leaves','D',0,NULL,54.2,NULL,33.1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,1900,NULL,'218',NULL),('Thlaspi arvense','Pennycress','Seed','D',0,NULL,25,45,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218','The figures given for fat were a range from 28.2 - 62.2 grammes.'),('Thymus vulgaris','Thyme','Leaves','D',7.8,276,9.1,7.4,63.9,18.6,11.7,1890,201,123.6,220,55,814,6.2,3800,0.51,0.4,4.94,NULL,NULL,'218',NULL),('Tribulus terrestris',NULL,'Leaves','F',79.09,NULL,7.22,NULL,NULL,NULL,4.6,1600,80,9.22,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,41,NULL,'218',NULL),('Trichosanthes ovigera','Japanese snake gourd','Fruit','D',0,316,15.8,0,78.9,8.8,5.3,333,596,17.5,NULL,NULL,2159,NULL,14210,0.7,0.9,12.3,105,NULL,'218',NULL),('Trichosanthes ovigera','Japanese snake gourd','Seed','F',NULL,NULL,33.8,56.3,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218','The report did not specify if this was the fresh or dry weight.'),('Trifolium pratense','Red clover','Leaves','F',81,NULL,4,0.7,NULL,2.6,2,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218',NULL),('Trigonella foenum-graecum','Fenugreek','Seed','F',6.2,NULL,23.2,8,10,9.8,4.3,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218',NULL),('Triticum aestivum','Bread wheat','Seed','F',13,340,11.7,2.2,72,2,1.7,40,377,3.5,NULL,NULL,400,NULL,NULL,0.55,0.11,4.8,NULL,NULL,'218','The figures given here are the median of a range given in the report.'),('Vaccaria hispanica',NULL,'Seed','D',NULL,NULL,15,2.5,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218','The report does not make it clear whether this is a zero moisture basis.'),('Vallisneria spiralis','Eel grass','Leaves','D',0,NULL,NULL,NULL,NULL,NULL,14.1,1154,3205,141,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'218',NULL),('Zea mays','Sweet corn','Seed','F',10.6,361,9.4,4.3,74.4,1.8,1.3,9,290,2.5,NULL,NULL,NULL,NULL,140,0.43,0.1,1.9,0,NULL,'218',NULL),('Ziziphus jujuba','Jujube','Fruit','D',0,350,7.3,1.2,84,4,3,130,168,3.5,NULL,12,1050,NULL,125,0.1,0.18,2.8,300,NULL,'218','The figures given here are the median of a range given in the report.'),('Ziziphus jujuba','Jujube','Leaves','D',0,337,11.8,4.3,75.3,14.3,8.6,1970,230,NULL,NULL,NULL,NULL,NULL,200,NULL,NULL,NULL,NULL,NULL,'218',NULL);
/*!40000 ALTER TABLE `composition` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-05-05 16:36:59
