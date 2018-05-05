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
-- Table structure for table `a_code`
--

DROP TABLE IF EXISTS `a_code`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `a_code` (
  `Description` varchar(255) DEFAULT NULL,
  `Code` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `a_code`
--

LOCK TABLES `a_code` WRITE;
/*!40000 ALTER TABLE `a_code` DISABLE KEYS */;
INSERT INTO `a_code` (`Description`, `Code`) VALUES ('Uncertain','un'),('Africa','af'),('Africa(C)','af(C)'),('Africa(N)','af(N)'),('Africa(NE)','af(ne)'),('Africa(NW)','af(nw)'),('Africa(S)','af(S)'),('Africa(W)','af(W)'),('Africa(Ghana)','af(GH)'),('Africa(Sahel)','af(sahel)'),('Africa(Burkina Faso)','af(BF)'),('Africa(Sudan)','af(SD)'),('Africa(Nigeria)','af(NG)'),('Africa(Ivory Coast)','af(CI)'),('Arctic','arctic'),('Asia','as'),('Asia(Afghanistan)','as(AF)'),('Asia(C)','as(C)'),('Asia(Caucusus)','as(cu)'),('Asia(China C)','as(CN(C))'),('Asia(China E)','as(CN(E))'),('Asia(China N)','as(CN(N))'),('Asia(China NE)','as(CN(ne))'),('Asia(China NW)','as(CN(nw))'),('Asia(China S)','as(CN(S))'),('Asia(China SE)','as(CN(se))'),('Asia(China SW)','as(CN(sw))'),('Asia(China W)','as(CN(W))'),('Asia(China)','as(CN'),('Asia(E)','as(E)'),('Asia(Himalayas)','as(him)'),('Asia(India)','as(IN)'),('Asia(Indonesia)','as(ID)'),('Asia(Japan)','as(JP)'),('Asia(Korea)','as(KD)'),('Asia(Manchuria)','as(man)'),('Asia(Mongolia)','as(mon)'),('Asia(Malysia)','as(MY)'),('Asia(Philippines)','as(PH)'),('Asia(N)','as(N)'),('Asia(NE)','as(ne)'),('Asia(NW)','as(nw)'),('Asia(Nepal)','as(NP)'),('Asia(Pakistan)','as(PK)'),('Asia(Russia)','as(RU)'),('Asia(S)','as(S)'),('Asia(SE)','as(se)'),('Asia(SW)','as(sw)'),('Asia(Siberia)','as(si)'),('Asia(Taiwan)','as(TW)'),('Asia(Tibet)','as(ti)'),('Asia(Tropical)','as(trop)'),('Asia(Turkistan)','as(tk)'),('Asia(W)','as(W)'),('Australia','AU'),('Australia(New South Wales)','AU(NSW)'),('Australia(Northern Territories)','AU(NT)'),('Australia(Queensland)','AU(Q)'),('Australia(South Australia)','AU(SA)'),('Australia(Tasmania)','AU(T)'),('Australia(Victoria)','AU(V)'),('Australia(Western Australia)','AU(WA)'),('Britain','UK'),('Britain(introduced)','UK(in)'),('Britain(native)','UK(ntv)'),('Britain(naturalised)','UK(nat)'),('C. America','ca'),('C. America(Mexico)','ca(MX)'),('Europe','eu'),('Europe(Balkans)','eu(balk)'),('Europe(C)','eu(C)'),('Europe(E)','eu(E)'),('Europe(N)','eu(N)'),('Europe(S)','eu(S)'),('Europe(SW)','eu(sw)'),('Europe(Scandinavia)','eu(scand)'),('Europe(W)','eu(W)'),('Europe(Germany)','eu(DE)'),('Europe(France)','eu(FR)'),('Europe(Netherlands)','eu(NL)'),('Ex Britain','extra(UK)'),('Ex Other','extra(ot)'),('Ex Temperate','extra(temp)'),('Ex cultivar','extra(cu)'),('Ex hybrid','extra(hy)'),('Ex uncertain','extra(un)'),('Mediterranean','med'),('Middle East','me'),('Middle East(Turkey)','me(TK)'),('Middle East(Iran)','me(IR)'),('Middle East(Iraq)','me(IQ)'),('N. America','na'),('N. America(Alaska)','na(AK)'),('N. America(C)','na(C)'),('N. America(Canada)','na(CA)'),('N. America(E)','na(E)'),('N. America(Greenland)','na(GL)'),('N. America(N)','na(N)'),('N. America(NE)','na(ne)'),('N. America(NW)','na(nw)'),('N. America(Rocky Mountains)','na(rocky)'),('N. America(S)','na(S)'),('N. America(SE)','na(se)'),('N. America(SW)','na(sw)'),('N. America(W)','na(W)'),('S. America','sa'),('S. America(Argentina)','sa(AR)'),('S. America(Brazil)','sa(BR)'),('S. America(C)','sa(C)'),('S. America(Chile)','sa(CL)'),('S. America(Colombia)','sa(CO)'),('S. America(Venezuela)','sa(VE)'),('S. America(E)','sa(E)'),('S. America(N)','sa(N)'),('S. America(Peru)','sa(PE)'),('S. America(S)','sa(S)'),('S. America(W)','sa(W)'),('New Zealand','NZ'),('Other','ot'),('Other Islands','is'),('West Indies','wi'),('West Indies(Dominican Republic)','wi(DO)'),('Temperate','temp'),('Tropics','trop'),('cosmopolitan','cosmo'),('cultivar','cu'),('hybrid','hy');
/*!40000 ALTER TABLE `a_code` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-05-05 16:36:57
