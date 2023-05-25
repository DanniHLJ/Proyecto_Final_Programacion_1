-- MySQL dump 10.13  Distrib 8.0.32, for Win64 (x86_64)
--
-- Host: localhost    Database: act11db
-- ------------------------------------------------------
-- Server version	8.0.32

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `clientes`
--

DROP TABLE IF EXISTS `clientes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `clientes` (
  `idCliente` int NOT NULL AUTO_INCREMENT,
  `nombres` varchar(60) DEFAULT NULL,
  `apellidos` varchar(60) DEFAULT NULL,
  `NIT` varchar(12) DEFAULT NULL,
  `genero` bit(1) DEFAULT NULL,
  `telefono` varchar(25) DEFAULT NULL,
  `correo_electronico` varchar(45) DEFAULT NULL,
  `fechaingreso` datetime DEFAULT NULL,
  PRIMARY KEY (`idCliente`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `clientes`
--

LOCK TABLES `clientes` WRITE;
/*!40000 ALTER TABLE `clientes` DISABLE KEYS */;
INSERT INTO `clientes` VALUES (1,'Daniel','González ','10184317',_binary '','55145200','hljdanni2023@gmail.com','2023-05-19 08:00:00'),(2,'Rocío ','Juárez','43171018',_binary '\0','47029980','eve123@gmail.com','2023-05-01 09:00:00'),(3,'Jafet','Morales','15645678',_binary '','50473695','moralesrobleromarcos@gmail.com','2023-05-20 14:00:00'),(4,'Luis','González','14725836',_binary '','36985214','luisgonzalez@gmail.com','2023-05-20 13:00:00'),(5,'Emer','Veliz','25874136',_binary '','25896471','emerveliz@gmail.com','2023-05-18 05:00:00');
/*!40000 ALTER TABLE `clientes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `compras`
--

DROP TABLE IF EXISTS `compras`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `compras` (
  `idCompra` int NOT NULL AUTO_INCREMENT,
  `no_orden_compra` int DEFAULT NULL,
  `idproveedor` int DEFAULT NULL,
  `fecha_orden` date DEFAULT NULL,
  `fechaingreso` datetime DEFAULT NULL,
  PRIMARY KEY (`idCompra`),
  KEY `FK_idproveedor_idx` (`idproveedor`),
  CONSTRAINT `FK_idproveedor` FOREIGN KEY (`idproveedor`) REFERENCES `proveedores` (`idProveedore`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `compras`
--

LOCK TABLES `compras` WRITE;
/*!40000 ALTER TABLE `compras` DISABLE KEYS */;
INSERT INTO `compras` VALUES (1,1225,1,'2023-05-20','2023-05-20 10:00:00'),(2,1404,2,'2023-05-20','2023-05-20 10:20:00'),(3,1322,1,'2023-05-20','2023-05-20 10:30:00'),(4,4564,3,'2023-05-20','2023-05-20 12:00:00'),(5,6021,5,'2023-05-20','2023-05-20 13:00:00');
/*!40000 ALTER TABLE `compras` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `compras_detalle`
--

DROP TABLE IF EXISTS `compras_detalle`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `compras_detalle` (
  `idcompra_detalle` bigint NOT NULL AUTO_INCREMENT,
  `idcompra` int DEFAULT NULL,
  `idproducto` int DEFAULT NULL,
  `cantidad` int DEFAULT NULL,
  `precio_costo_unitario` decimal(8,2) DEFAULT NULL,
  PRIMARY KEY (`idcompra_detalle`),
  KEY `FK_idcompra_idx` (`idcompra`),
  KEY `FK_idproducto_idx` (`idproducto`),
  CONSTRAINT `FK_idcompra` FOREIGN KEY (`idcompra`) REFERENCES `compras` (`idCompra`) ON UPDATE CASCADE,
  CONSTRAINT `FK_idproducto` FOREIGN KEY (`idproducto`) REFERENCES `productos` (`idProducto`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `compras_detalle`
--

LOCK TABLES `compras_detalle` WRITE;
/*!40000 ALTER TABLE `compras_detalle` DISABLE KEYS */;
INSERT INTO `compras_detalle` VALUES (1,1,2,2,10000.00),(2,2,1,1,5000.00),(3,3,3,3,11000.00),(4,4,5,5,1600.00),(5,5,4,4,2500.00);
/*!40000 ALTER TABLE `compras_detalle` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `empleados`
--

DROP TABLE IF EXISTS `empleados`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `empleados` (
  `idEmpleado` int NOT NULL AUTO_INCREMENT,
  `nombres` varchar(60) DEFAULT NULL,
  `apellidos` varchar(60) DEFAULT NULL,
  `direccion` varchar(80) DEFAULT NULL,
  `telefono` varchar(25) DEFAULT NULL,
  `DPI` varchar(15) DEFAULT NULL,
  `genero` bit(1) DEFAULT NULL,
  `fecha_nacimiento` date DEFAULT NULL,
  `idPuesto` smallint DEFAULT NULL,
  `fecha_inicio_labores` date DEFAULT NULL,
  `fechaingreso` datetime DEFAULT NULL,
  PRIMARY KEY (`idEmpleado`),
  KEY `idPuesto_idx` (`idPuesto`),
  CONSTRAINT `FK_idPuesto` FOREIGN KEY (`idPuesto`) REFERENCES `puestos` (`idPuesto`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `empleados`
--

LOCK TABLES `empleados` WRITE;
/*!40000 ALTER TABLE `empleados` DISABLE KEYS */;
INSERT INTO `empleados` VALUES (1,'Juan','Perez','Antigua','55645854','78945645612',_binary '','1999-01-13',3,'2023-04-12','2023-04-15 09:00:00'),(2,'Daniel','González','Chimaltenango','55145200','12345678911',_binary '','2004-04-12',1,'2022-01-10','2022-01-15 00:00:00'),(3,'Jafet','Morales','Sane Pedro','55896589','25845698565',_binary '','2000-06-04',4,'2022-02-11','2022-02-15 08:00:00'),(4,'Jose','González','Chimaltenango','25698541','23652365236',_binary '','1998-05-15',2,'2022-05-15','2022-05-15 09:00:00'),(5,'Maria','Hernandez','Jutiapa','58965475','23125421236',_binary '\0','2000-04-14',5,'2023-06-11','2023-06-15 00:00:00');
/*!40000 ALTER TABLE `empleados` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `marcas`
--

DROP TABLE IF EXISTS `marcas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `marcas` (
  `idMarca` smallint NOT NULL AUTO_INCREMENT,
  `marca` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`idMarca`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='		';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `marcas`
--

LOCK TABLES `marcas` WRITE;
/*!40000 ALTER TABLE `marcas` DISABLE KEYS */;
INSERT INTO `marcas` VALUES (1,'Samsung'),(2,'LG'),(3,'Sony'),(4,'Huawei'),(5,'Apple'),(6,'Xiaomi'),(7,'HP'),(8,'Dell'),(9,'Acer');
/*!40000 ALTER TABLE `marcas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `productos`
--

DROP TABLE IF EXISTS `productos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `productos` (
  `idProducto` int NOT NULL AUTO_INCREMENT,
  `producto` varchar(50) DEFAULT NULL,
  `idMarca` smallint DEFAULT NULL,
  `Descripcion` varchar(100) DEFAULT NULL,
  `Imagen` varchar(30) DEFAULT NULL,
  `precio_costo` decimal(8,2) DEFAULT NULL,
  `precio_venta` decimal(8,2) DEFAULT NULL,
  `existencia` int DEFAULT NULL,
  `fecha_ingreso` datetime DEFAULT NULL,
  PRIMARY KEY (`idProducto`),
  KEY `FK_idMarca_idx` (`idMarca`),
  CONSTRAINT `FK_idMarca` FOREIGN KEY (`idMarca`) REFERENCES `marcas` (`idMarca`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `productos`
--

LOCK TABLES `productos` WRITE;
/*!40000 ALTER TABLE `productos` DISABLE KEYS */;
INSERT INTO `productos` VALUES (1,'Television 4K',1,'52\" De tamaño, hdmi 2.0',NULL,3000.00,5000.00,3,'2023-05-20 10:00:00'),(2,'S23 128GB',1,'6000 milieanperes',NULL,6000.00,10000.00,5,'2023-05-20 10:00:00'),(3,'Television 4K',3,'72\" De tamaño, hdmi 2.0',NULL,7000.00,11000.00,6,'2023-05-20 10:00:00'),(4,'Monitor Gaming',2,'144hz, 1 ips de respuesta',NULL,1600.00,2500.00,2,'2023-05-20 10:00:00'),(5,'Audífonos inear',3,'IP68, 32 horas de batería',NULL,900.00,1600.00,2,'2023-05-20 10:00:00');
/*!40000 ALTER TABLE `productos` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `proveedores`
--

DROP TABLE IF EXISTS `proveedores`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `proveedores` (
  `idProveedore` int NOT NULL AUTO_INCREMENT,
  `proveedor` varchar(60) DEFAULT NULL,
  `nit` varchar(12) DEFAULT NULL,
  `direccion` varchar(80) DEFAULT NULL,
  `telefono` varchar(25) DEFAULT NULL,
  PRIMARY KEY (`idProveedore`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `proveedores`
--

LOCK TABLES `proveedores` WRITE;
/*!40000 ALTER TABLE `proveedores` DISABLE KEYS */;
INSERT INTO `proveedores` VALUES (1,'HellwetPackart','12345678','Ciudad ','2589365'),(2,'Dell','25478967','Ciudad','6985742'),(3,'LG','58745632','Ciudad','2546985'),(4,'Samsung','56324563','Ciudad','2541236'),(5,'Apple','89657458','Chimaltenango','6985336');
/*!40000 ALTER TABLE `proveedores` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `puestos`
--

DROP TABLE IF EXISTS `puestos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `puestos` (
  `idPuesto` smallint NOT NULL AUTO_INCREMENT,
  `puesto` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`idPuesto`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `puestos`
--

LOCK TABLES `puestos` WRITE;
/*!40000 ALTER TABLE `puestos` DISABLE KEYS */;
INSERT INTO `puestos` VALUES (1,'Gerente'),(2,'Asistente'),(3,'Administrador'),(4,'Programador'),(5,'Vendedor');
/*!40000 ALTER TABLE `puestos` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ventas`
--

DROP TABLE IF EXISTS `ventas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `ventas` (
  `idVenta` int NOT NULL AUTO_INCREMENT,
  `notafactura` int DEFAULT NULL,
  `serie` char(1) DEFAULT NULL,
  `fechafactura` date DEFAULT NULL,
  `idcliente` int DEFAULT NULL,
  `idempleado` int DEFAULT NULL,
  `fechaingreso` datetime DEFAULT NULL,
  PRIMARY KEY (`idVenta`),
  KEY `FK_idcliente_idx` (`idcliente`),
  KEY `FK_idempleado_idx` (`idempleado`),
  CONSTRAINT `FK_idcliente` FOREIGN KEY (`idcliente`) REFERENCES `clientes` (`idCliente`) ON UPDATE CASCADE,
  CONSTRAINT `FK_idempleado` FOREIGN KEY (`idempleado`) REFERENCES `empleados` (`idEmpleado`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ventas`
--

LOCK TABLES `ventas` WRITE;
/*!40000 ALTER TABLE `ventas` DISABLE KEYS */;
INSERT INTO `ventas` VALUES (1,2550,'6','2022-04-16',1,5,'2022-04-16 10:00:00'),(2,1560,'6','2022-04-16',1,5,'2022-04-16 10:00:00'),(3,5889,'2','2022-04-22',2,5,'2022-04-22 11:00:00'),(4,6997,'2','2022-04-22',2,5,'2022-04-22 11:00:00'),(5,1122,'4','2022-06-14',3,5,'2022-06-14 10:00:00');
/*!40000 ALTER TABLE `ventas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ventas-detalle`
--

DROP TABLE IF EXISTS `ventas-detalle`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `ventas-detalle` (
  `idventa_-detalle` bigint NOT NULL AUTO_INCREMENT,
  `idVenta` int DEFAULT NULL,
  `idProducto` int DEFAULT NULL,
  `cantidad` varchar(45) DEFAULT NULL,
  `precio_unitario` decimal(8,2) DEFAULT NULL,
  PRIMARY KEY (`idventa_-detalle`),
  KEY `FK_idVenta_idx` (`idVenta`),
  KEY `FK_idProducto_idx` (`idProducto`),
  CONSTRAINT `FK_idProductos2` FOREIGN KEY (`idProducto`) REFERENCES `productos` (`idProducto`) ON UPDATE CASCADE,
  CONSTRAINT `FK_idVenta` FOREIGN KEY (`idVenta`) REFERENCES `ventas` (`idVenta`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ventas-detalle`
--

LOCK TABLES `ventas-detalle` WRITE;
/*!40000 ALTER TABLE `ventas-detalle` DISABLE KEYS */;
INSERT INTO `ventas-detalle` VALUES (1,1,1,'2',5000.00),(2,2,2,'1',6000.00),(3,3,4,'1',10000.00),(4,4,5,'2',1600.00),(5,5,3,'1',7000.00);
/*!40000 ALTER TABLE `ventas-detalle` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-05-21 12:49:39
