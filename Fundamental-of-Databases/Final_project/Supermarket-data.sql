USE supermarket;

INSERT INTO CustomerType VALUES('CT00S','Silver'),
('CT00G','Gold'),
('CT00P','Platinum'),
('CT0PR','Premium');


INSERT INTO Employee VALUES
("EMP1001", "Công Huy", "500933", "1982-12-21", "Cong218@gmail.com", "249 Đà Nẵng", "female"),
("EMP1002", "Thành Quỳnh", "995468", "1982-4-14", "yen135@gmail.com", "122 Hải Dương", "male"),
("EMP1003", "Đức Mai", "330098", "1991-11-22", "Van807@gmail.com", "43 Cần Thơ", "female"),
("EMP1004", "Xuân Ái", "796781", "1988-2-3", "Vy129@gmail.com", "281 Hưng Yên", "female"),
("EMP1005", "Yên Huy", "989091", "1983-7-4", "Huy789@gmail.com", "107 Hà Tĩnh", "male"),
("EMP1006", "Xuân Ngọc", "838164", "2002-10-15", "Huy770@gmail.com", "186 Bình Định", "male"),
("EMP1007", "Duy Lan", "317199", "2001-2-7", "Vi220@gmail.com", "252 Ninh Thuận", "male"),
("EMP1008", "Vỹ Hoài", "553030", "1982-6-9", "Khai634@gmail.com", "140 Quảng Trị", "female"),
("EMP1009", "Thu Thiện", "716221", "1998-2-22", "Duy384@gmail.com", "173 Hà Nội", "female"),
("EMP1010", "Minh Yến", "925574", "1998-9-24", "Thanh238@gmail.com", "160 Thái Bình", "male"),
("EMP2001", "Hoài Thành", "560504", "1982-9-2", "Thanh25@gmail.com", "95 Hải Phòng", "male"),
("EMP2002", "Như An", "710049", "1984-10-2", "Tram394@gmail.com", "99 Quảng Nam", "male"),
("EMP2003", "Hiếu Hải", "532454", "1988-7-24", "an646@gmail.com", "240 Thái Bình", "male"),
("EMP2004", "Ngọc Thu", "551087", "1991-7-27", "Huy513@gmail.com", "204 Hà Nội", "male"),
("EMP2005", "Thu Minh", "868110", "1983-6-19", "Cong32@gmail.com", "26 Hải Phòng", "female"),
("EMP2006", "Trâm Đức", "607859", "1983-4-24", "Xuan894@gmail.com", "163 Bắc Ninh", "female");

INSERT INTO Block VALUES('A1','Grocery','EMP1001'),
('A2','Daily Needs','EMP1003'),
('B1','Men Fashion','EMP1002'),
('B2','Women Fashion','EMP1006'),
('B3','Kids Wear','EMP1007'),
('B4','Footwear','EMP1009'),
('B5','Watches','EMP1010'),
('C1','Electronics','EMP1004'),
('C2','Dining & Serving','EMP1005'),
('C3','Stationary','EMP1008');


INSERT INTO OfferDetails VALUES('OFF10','Discount','10 %off','2020-01-01','2021-03-31'),
('THREE+ONE','Bonanza','Buy 3 product and get one free','2021-05-01','2021-09-28'),
('SUMMER25','Summer offer','25% off','2021-03-05','2021-05-28'),
('WINTER20','Winter offer','20% off','2021-11-01','2022-02-28'),
('SUMMER5','Summer offer','5% off','2022-03-01','2022-06-28'),
('WINTER5','Winter offer','5% off','2021-11-01','2022-02-28'),
('KHUSIWALIDIWALI','Diwali offer','15% off','2022-10-01','2023-10-20'),
('RANGBHARIHOLI','Holi offer','15% off','2020-03-01','2020-03-20'),
('CASH10','Cash payment offer','10% off','2022-01-01','2022-03-31'),
('CREDIT5','Credit card offer','5% off','2021-01-01','2023-03-31'),
('DEBIT5','Debit card offer','5% off','2021-01-01','2023-03-31'),
('PAYTM8','Paytm offer','8% off','2021-01-01','2023-03-31');

INSERT INTO PaymentMode VALUES('PAY001','Cash','CASH10'),
('PAY002','Credit card','CREDIT5'),
('PAY003','Debit card','DEBIT5'),
('PAY004','Paytm','PAYTM8');

INSERT INTO Warehouse VALUES('WARA001','AWARE'),
('WARA002','BWAR'),
('WARA003','CWAR'),
('WARB001','DWAR'),
('WARB002','EWAR'),
('WARC001','FWAR'),
('WARC002','GWAR'),
('WARC003','HWAR');


INSERT INTO Customer VALUES("CTM00001", "Ái Xuân", "804958", "1988-02-12", "duc788@gmail.com", "191 Bắc Ninh", "male", "CT0PR", "2025-9-25", "2021-10-1"),
("CTM00002", "Thành Hải", "545366", "1987-07-19", "Lan247@gmail.com", "246 Bắc Ninh", "male", "CT0PR", "2024-2-24", "2021-4-8"),
("CTM00003", "Khải Thuỷ", "533423", "1989-03-09", "Bao833@gmail.com", "47 Hải Dương", "male", "CT0PR", "2026-1-2", "2021-3-2"),
("CTM00004", "Huy Minh", "696220", "1993-01-21", "Thanh878@gmail.com", "68 Đà Nẵng", "male", "CT0PR", "2024-7-23", "2020-1-10"),
("CTM00005", "Hải Thuỷ", "722036", "1991-08-26", "Vy176@gmail.com", "229 Quảng Trị", "female", "CT0PR", "2023-3-20", "2020-2-7"),
("CTM00006", "Đức Thành", "782713", "1980-04-26", "Bao277@gmail.com", "214 Quảng Nam", "female", "CT0PR", "2031-3-15", "2021-10-20"),
("CTM00007", "Thiện Thành", "444409", "1988-01-17", "Bao482@gmail.com", "135 Phú Yên", "female", "CT00G", "2023-8-21", "2021-7-19"),
("CTM00008", "Duy Thiện", "925455", "2002-03-23", "yen97@gmail.com", "260 Quảng Nam", "male", "CT00P", "2022-5-16", "2021-1-9"),
("CTM00009", "An Hoàng", "566112", "1982-03-20", "Gia609@gmail.com", "56 Hồ Chí Minh", "female", "CT0PR", "2029-3-23", "2020-11-10"),
("CTM00010", "Công Anh", "484990", "1988-05-15", "Thao633@gmail.com", "86 Hà Nam", "female", "CT00S", "2025-2-11", "2020-11-16"),
("CTM00011", "Ái Vân", "574387", "1997-02-13", "Vy483@gmail.com", "58 Bình Định", "male", "CT00S", "2023-3-12", "2021-3-15"),
("CTM00012", "Thu Duy", "920064", "1995-02-12", "Thien831@gmail.com", "200 Quảng Ngãi", "female", "CT00P", "2025-8-7", "2020-8-19"),
("CTM00013", "Xuân Hoàng", "339654", "1989-10-10", "Thanh919@gmail.com", "241 Cần Thơ", "male", "CT00G", "2023-1-11", "2020-7-4"),
("CTM00014", "Công Vỹ", "699544", "2001-08-10", "anh61@gmail.com", "63 Quảng Trị", "male", "CT0PR", "2028-6-11", "2020-12-9"),
("CTM00015", "Vị Lan", "785145", "1984-10-06", "Hieu853@gmail.com", "7 Đà Nẵng", "female", "CT00S", "2024-4-7", "2020-6-2"),
("CTM00016", "Lan Vân", "342077", "1984-11-09", "Thien102@gmail.com", "19 Hưng Yên", "female", "CT00G", "2026-6-23", "2021-1-13"),
("CTM00017", "Ái Vỹ", "507409", "1995-09-28", "Ngoc720@gmail.com", "148 Quảng Ngãi", "female", "CT00S", "2024-12-5", "2020-1-4"),
("CTM00018", "Hoài Vân", "623892", "1990-02-17", "ai152@gmail.com", "137 Quảng Ngãi", "male", "CT00S", "2026-1-11", "2020-5-11"),
("CTM00019", "Ngọc Thiện", "428989", "1990-08-09", "dinh630@gmail.com", "269 Khánh Hòa", "male", "CT00G", "2030-3-18", "2021-10-5"),
("CTM00020", "Yên Hải", "299155", "2003-08-28", "Ngoc454@gmail.com", "261 Bình Định", "female", "CT00S", "2022-5-11", "2021-2-4"),
("CTM00021", "Hiếu Khánh", "779433", "1983-03-13", "Tuan626@gmail.com", "5 Quảng Ngãi", "male", "CT0PR", "2028-8-15", "2020-10-1"),
("CTM00022", "Huy Ngọc", "915405", "2003-07-28", "Hoang632@gmail.com", "261 Nam Định", "female", "CT00P", "2031-5-9", "2020-6-12"),
("CTM00023", "Anh Quỳnh", "604291", "1984-06-10", "yen648@gmail.com", "42 Quảng Trị", "female", "CT0PR", "2029-11-19", "2021-10-13"),
("CTM00024", "Mai Bảo", "740340", "1996-01-14", "Mai514@gmail.com", "17 Quảng Bình", "female", "CT00P", "2027-4-9", "2021-10-8"),
("CTM00025", "An Quỳnh", "745890", "1985-03-18", "yen548@gmail.com", "197 Thừa Thiên Huế", "female", "CT00P", "2022-4-12", "2021-3-4"),
("CTM00026", "Yến Tuấn", "503217", "1997-04-23", "Huy122@gmail.com", "213 Đà Nẵng", "female", "CT00P", "2022-3-16", "2020-7-7"),
("CTM00027", "Thảo Vân", "391932", "1983-09-17", "Tram526@gmail.com", "119 Khánh Hòa", "male", "CT00S", "2023-3-22", "2021-4-16"),
("CTM00028", "Khánh Thu", "522472", "1986-12-05", "an958@gmail.com", "71 Hưng Yên", "male", "CT0PR", "2029-4-15", "2020-7-13"),
("CTM00029", "Nhật An", "665667", "1987-09-24", "Xuan466@gmail.com", "128 Hải Dương", "male", "CT00G", "2028-4-12", "2021-1-1"),
("CTM00030", "Yên Yến", "537726", "1983-08-13", "Vi640@gmail.com", "90 Hồ Chí Minh", "female", "CT00S", "2026-10-14", "2021-10-1"),
("CTM00031", "Huy Như", "728430", "1999-07-17", "Khanh413@gmail.com", "231 Ninh Bình", "male", "CT0PR", "2025-9-3", "2020-1-5"),
("CTM00032", "Khánh Minh", "326551", "1987-11-20", "Tram863@gmail.com", "158 Đà Nẵng", "female", "CT00S", "2028-11-9", "2020-5-9"),
("CTM00033", "Mạnh An", "726172", "1990-05-22", "Hai675@gmail.com", "278 Bình Định", "female", "CT00S", "2028-2-23", "2021-2-19"),
("CTM00034", "Mạnh Hải", "834732", "1991-12-03", "Bao724@gmail.com", "167 Bắc Ninh", "male", "CT00P", "2026-7-20", "2020-11-8"),
("CTM00035", "Công Gia", "332840", "1994-10-23", "Xuan832@gmail.com", "230 Hồ Chí Minh", "male", "CT00P", "2028-11-15", "2021-12-16"),
("CTM00036", "Công Hoài", "765415", "2000-01-18", "Hai218@gmail.com", "94 Cần Thơ", "female", "CT0PR", "2023-6-19", "2021-11-12"),
("CTM00037", "Như Khánh", "509581", "1989-09-09", "Manh856@gmail.com", "150 Ninh Thuận", "female", "CT00S", "2022-6-26", "2021-2-16"),
("CTM00038", "Hoài Vị", "792180", "1999-11-28", "Hai832@gmail.com", "198 Bình Định", "female", "CT00S", "2022-6-23", "2021-10-1"),
("CTM00039", "Thuỷ Vân", "952140", "1996-02-11", "Thao951@gmail.com", "139 Ninh Bình", "male", "CT00S", "2025-8-27", "2021-7-12"),
("CTM00040", "Yến Công", "606990", "1990-02-25", "Tuan415@gmail.com", "120 Hà Nội", "male", "CT00S", "2025-7-3", "2021-3-8"),
("CTM00041", "Công Thảo", "853156", "2003-05-01", "Khai279@gmail.com", "108 Hải Dương", "female", "CT0PR", "2023-6-14", "2021-8-19"),
("CTM00042", "Vỹ Mai", "686474", "1980-10-16", "yen324@gmail.com", "125 Quảng Trị", "female", "CT0PR", "2028-2-22", "2020-3-10"),
("CTM00043", "Hoàng Xuân", "269423", "1991-03-21", "anh517@gmail.com", "244 Thừa Thiên Huế", "female", "CT00S", "2028-10-13", "2021-8-1"),
("CTM00044", "Vân Tuấn", "794827", "2003-04-24", "Huy308@gmail.com", "204 Quảng Bình", "female", "CT00S", "2032-2-13", "2021-6-14"),
("CTM00045", "Hiếu Vỹ", "917404", "1980-08-18", "Ngoc235@gmail.com", "102 Cần Thơ", "female", "CT0PR", "2028-5-1", "2020-4-5"),
("CTM00046", "Thu Thanh", "827869", "1980-01-17", "Quynh372@gmail.com", "77 Ninh Bình", "female", "CT0PR", "2023-9-5", "2021-12-13"),
("CTM00047", "Mạnh Huy", "920694", "2003-02-21", "ai297@gmail.com", "289 Hà Tĩnh", "male", "CT00P", "2025-8-4", "2020-2-7"),
("CTM00048", "Yến Tuấn", "321890", "1980-11-09", "yen765@gmail.com", "107 Khánh Hòa", "male", "CT00S", "2024-12-20", "2021-9-7"),
("CTM00049", "Thu Thanh", "451850", "1984-10-10", "Thu933@gmail.com", "91 Nam Định", "male", "CT0PR", "2022-9-16", "2021-7-17"),
("CTM00050", "Công Yến", "717706", "1988-06-13", "Thuy675@gmail.com", "117 Hà Nội", "female", "CT00P", "2023-6-13", "2020-1-11");


INSERT INTO Category VALUES('GRO001','Fruits & Vegetables','A1','WARA001'),
('GRO002','Spices','A1','WARB001'),
('GRO003','Dry Fruits','A1','WARC003'),
('GRO004','Rice & Pulses','A1','WARC002'),
('GRO005','Oils','A1','WARB001'),
('DN001','Soaps & Detergents','A2','WARC001'),
('DN002','Coffee, Tea & Beverages','A2','WARB002'),
('DN003','Fragrances','A2','WARC001'),
('MF001','Men Shirts','B1','WARA003'),
('MF002','Men Trousers','B1','WARC002'),
('MF003','Men Innerwear','B1','WARB001'),
('WF001','Women Tops','B2','WARC002'),
('WF002','Women Jeans','B2','WARB002'),
('WF003','Women Kurti','B2','WARC001'),
('WF004','Lingerie','B2','WARA002'),
('KW001','Tops & Tees','B3','WARC003'),
('KW002','Baby Jeans','B3','WARB002'),
('KW003','Kids Ethnic Wear','B3','WARC002'),
('FW001','Men Footwear','B4','WARC001'),
('FW002','Women Footwear','B4','WARB001'),
('FW003','Kids Footwear','B4','WARA002'),
('CLK001','Men Watches','B5','WARA003'),
('CLK002','Women Watches','B5','WARA002'),
('CLK003','Kids Watches','B5','WARA001'),
('ELC001','Smartphones','C1','WARC001'),
('ELC002','Tablets','C1','WARB002'),
('ELC003','Laptop','C1','WARC002'),
('ELC004','LED Television','C1','WARA001'),
('ELC005','Speaker , Woofer & MP3 player','C1','WARA001'),
('DNG001','TableWare','C2','WARA001'),
('DNG002','Storage','C2','WARC003'),
('DNG003','Kitchen Tools','C2','WARC001'),
('DNG004','Cooking Essentials','C2','WARA003'),
('STN001','Office Supplies','C3','WARA002'),
('STN002','Notebooks, Writing Pads & Diaries','C3','WARA003'),
('STN003','Art & Craft Supplies','C3','WARB001'),
('STN004','Pens, Pencils & Writing Supplies','C3','WARC001');

INSERT INTO InvoiceDetails VALUES('AAA001','CTM00001','5000.223','2021-04-01','PAY001','EMP2001'),
('AAA002','CTM00013','455000.11','2021-04-01','PAY002','EMP2003'),
('AAA003','CTM00024','9865.22','2022-04-01','PAY003','EMP2004'),
('AAB001','CTM00037','8000.25','2022-03-05','PAY004','EMP2002'),
('AAB002','CTM00044','56666.22','2022-03-05','PAY001','EMP2005'),
('AAH001','CTM00016','7889.42','2022-02-15','PAY002','EMP2006'),
('AAC001','CTM00031','9999.88','2021-02-15','PAY003','EMP2005'),
('AAC002','CTM00016','7852.88','2022-02-15','PAY003','EMP2005'),
('AAD001','CTM00034','400.88','2021-01-15','PAY001','EMP2002'),
('AAD002','CTM00044','52224.88','2022-01-15','PAY002','EMP2001'),
('AAD003','CTM00040','6655.88','2022-01-15','PAY003','EMP2004'),
('AAE001','CTM00044','488.88','2021-12-30','PAY001','EMP2003'),
('AAE002','CTM00039','300.88','2022-12-30','PAY004','EMP2002'),
('AAF001','CTM00041','400.88','2022-01-15','PAY003','EMP2002'),
('AAF002','CTM00022','52224.88','2021-01-15','PAY002','EMP2001'),
('AAG003','CTM00041','6655.88','2022-01-15','PAY003','EMP2004'),
('AAG001','CTM00031','488.88','2022-03-30','PAY001','EMP2003'),
('AAG002','CTM00024','3000.88','2021-04-30','PAY004','EMP2002'),
('AAI001','CTM00001','6000.223','2022-05-01','PAY001','EMP2001'),
('AAI002','CTM00007','495000.11','2022-04-29','PAY002','EMP2003'),
('AAJ003','CTM00003','19865.22','2022-04-12','PAY003','EMP2004'),
('AAJ001','CTM00005','800.25','2021-02-05','PAY004','EMP2002'),
('AAJ002','CTM00007','5666.22','2022-07-07','PAY001','EMP2005'),
('AAK001','CTM00015','78289.42','2022-02-12','PAY002','EMP2006'),
('AAK002','CTM00006','999.88','2022-06-15','PAY003','EMP2005'),
('AAK003','CTM00013','4000.88','2022-01-15','PAY001','EMP2006'),
('AAL002','CTM00011','23224.88','2022-02-15','PAY002','EMP2001'),
('AAL003','CTM00011','6655.88','2022-01-12','PAY003','EMP2004'),
('AAM001','CTM00012','4880.88','2022-11-30','PAY001','EMP2001'),
('AAM002','CTM00019','300.88','2022-11-30','PAY004','EMP2002'),
('AAN001','CTM00008','40030.88','2022-07-15','PAY003','EMP2002'),
('AAN002','CTM00002','5222.88','2022-01-15','PAY002','EMP2001'),
('AAN003','CTM00014','66555.88','2021-01-15','PAY003','EMP2004'),
('AAP001','CTM00013','4880.88','2022-04-30','PAY001','EMP2003'),
('AAP002','CTM00002','300.88','2022-04-28','PAY004','EMP2002');


INSERT INTO Product VALUES('PI10001','Apple','CASCADIAN FARM','270','1kg','300','GRO001','OFF10','500','300'),
('PI10002','Banana','HARVEST FARM','36','1kg','40','GRO001','OFF10','200','100'),
('PI10003','Orange','365 ORGANIC','180','1kg','200','GRO001','OFF10','300','200'),
('PI10004','Brinjal','MARKET SIDE','36','1kg','40','GRO001','OFF10','100','50'),
('PI10005','Potato','MARKET SIDE','18','1kg','20','GRO001','OFF10','100','50'),
    
    
('PI10011','turmeric','EVEREST','45','0.05kg','50','GRO002','OFF10','100','200'),
('PI10012','chilli powder','EVEREST','36','0.05kg','40','GRO002','OFF10','100','200'),
('PI10013','Salt','TATA','18','1 kg','20','GRO002','OFF10','200','100'),
('PI10014','Chicken Masala','EVEREST','36','0.1kg','40','GRO002','OFF10','100','150'),
    
('PI10021','walnut','sunsweet','450','0.25kg','500','GRO003','OFF10','100','200'),
('PI10022','cashew','Tulsi','360','0.25kg','400','GRO003','OFF10','100','200'),
('PI10023','apricot','delicious','180','0.5kg','200','GRO003','OFF10','200','100'),
('PI10024','coconut','balaji','36','0.25kg','40','GRO003','OFF10','100','150'),


('PI10031','rice','India Gate','90','1kg','100','GRO004','OFF10','200','300'),
('PI10032','brown rice','fabindia','72','1kg','80','GRO004','OFF10','300','200'),
('PI10033','wheat','aashirwad','27','1kg','30','GRO004','OFF10','400','200'),
('PI10034','Urad daal','balaji','108','1kg','120','GRO004','OFF10','300','250'),

('PI10041','soyabean oil','fortune','90','1kg','100','GRO005','OFF10','100','100'),
('PI10042','canola oil','saffola','135','1kg','150','GRO005','OFF10','50','100'),
('PI10043','mustard oil','nature fresh','117','1kg','130','GRO005','OFF10','200','100'),
('PI10044','sunflower oil','nutrela','108','1kg','120','GRO005','OFF10','100','110'),

('PI10081','body soap','cinthol','36','0.05kg','40','DN001','OFF10','200','100'),
('PI10082','cloth soap','rin','18','0.05kg','20','DN001','OFF10','300','100'),
('PI10083','detergent','surf excel','117','0.5kg','130','DN001','OFF10','100','100'),
('PI10084','floor cleaner','lizol','54','1kg','60','DN001','OFF10','70','50'),

('PI10091','tea','tata','36','0.05kg','40','DN002','OFF10','200','100'),
('PI10092','coffee','nescafe','126','0.05kg','140','DN002','OFF10','350','100'),
('PI10093','Cappuccino','Bru','117','0.5kg','130','DN002','OFF10','100','100'),
('PI10094','leaf-tea','lipton','54','0.05kg','60','DN002','OFF10','200','160'),

('PI10101','perfume','adidas','360','0.15kg','400','DN003','OFF10','200','100'),
('PI10102','deodrant','axe','126','0.15kg','140','DN003','OFF10','350','100'),
('PI10103','room freshner','odonil','117','0.15kg','130','DN003','OFF10','100','100'),

('PI10111','shirt','mufti','1260','1','1400','MF001','OFF10','200','100'),
('PI10112','half sleeve','lee','1170','1','1300','MF001','OFF10','350','100'),
('PI10113','t-shirt','jack and jones','1080','1','1200','MF001','OFF10','100','100'),


('PI10121','jeans','mufti','1260','1','1400','MF002','OFF10','200','100'),
('PI10122','trousers','lee','1170','1','1300','MF002','OFF10','350','100'),
('PI10123','formal','blackberry','1080','1','1200','MF002','OFF10','100','100'),

('PI10131','banyan','rupa frontline','126','1','140','MF003','OFF10','60','100'),
('PI10132','underwear','jockey','225','1','250','MF003','OFF10','50','100'),
('PI10133','handkerchief','blackberry','90','1','100','MF003','OFF10','50','100'),
('PI10134','socks','jockey','90','1','100','MF003','OFF10','50','100'),


('PI10141','full sleeve top','lee','1260','1','1400','WF001','OFF10','60','100'),
('PI10142','half sleeve top','lee cooper','540','1','600','WF001','OFF10','50','100'),
('PI10143','sleeveless','jockey','990','1','1100','WF001','OFF10','50','100'),
('PI10144','formal','diva','990','1','1100','WF001','OFF10','50','100'),


('PI10151','jeans','mufti','1260','1','1400','WF002','OFF10','200','100'),
('PI10152','trousers','lee','1170','1','1300','WF002','OFF10','350','100'),
('PI10153','formal','karisma','1080','1','1200','WF002','OFF10','100','100'),

('PI10161','banyan','amul','126','1','140','WF004','OFF10','60','100'),
('PI10162','underwear','jockey','225','1','250','WF004','OFF10','50','100'),
('PI10163','handkerchief','blackberry','90','1','100','WF004','OFF10','50','100'),
('PI10164','socks','jockey','90','1','100','WF004','OFF10','50','100'),
('PI10165','BRA','haynes','180','1','200','WF004','OFF10','50','100'),

('PI10171','top','lilliput','360','1','400','KW001','OFF10','80','100'),
('PI10172','lower','champion','270','1','300','KW001','OFF10','80','100'),
('PI10173','combo','lilliput','810','1','900','KW001','OFF10','80','100'),

('PI10181','half jeans','lilliput','450','1','500','KW002','OFF10','60','100'),
('PI10182','full jeans','kidzee','720','1','800','KW002','OFF10','70','100'),
('PI10183','trouser','lilliput','810','1','900','KW002','OFF10','90','100'),

('PI10191','Kurata-Payzama','Bad-boys','900','1','1000','KW003','OFF10','70','100'),
('PI10192','Top-Skirt','Biba','540','1','600','KW003','OFF10','40','100'),
('PI10193','Sherwani','Gkidz','720','1','800','KW003','OFF10','60','100'),
('PI10194','Lehenga-choli','Biba','1350','1','1500','KW003','OFF10','90','100'),

('PI10201','Sneakers','Levis','1350','1','1500','FW001','OFF10','70','100'),
('PI10202','Loafers','Nike','1125','1','1500','FW001','SUMMER25','60','100'),
('PI10203','Casual Shoes','Reebok','1800','1','2000','FW001','OFF10','50','100'),
('PI10204','Formal Shoes','Columbus','2700','1','3000','FW001','OFF10','90','100'),
('PI10205','Flip-flops','Puma','225','1','300','FW001','SUMMER25','30','100'),
('PI10206','Floaters','Adidas','900','1','1200','FW001','SUMMER25','40','100'),

('PI10211','Wedges','Lavie','3150','1','3500','FW002','OFF10','70','100'),
('PI10212','Heels','Catwalk','2250','1','2500','FW002','OFF10','90','100'),
('PI10213','Casual Shoes','Reebok','1620','1','1800','FW002','OFF10','50','100'),
('PI10214','Ballerians','Bata','1350','1','1500','FW002','OFF10','80','100'),
('PI10215','Flip-flops','Action','150','1','200','FW002','SUMMER25','30','100'),
('PI10216','Floaters','Sparx','900','1','1200','FW002','SUMMER25','40','100'),

('PI10221','Sandals','Puma','720','1','800','FW003','OFF10','70','100'),
('PI10222','Shoes','Action-campus','900','1','1000','FW003','OFF10','90','100'),
('PI10223','Flip-flops','Bata','180','1','200','FW003','OFF10','50','100'),

('PI10301','Digital','Fastrack','4250','1','5000','CLK001','KHUSIWALIDIWALI','80','100'),
('PI10302','Analogue','Sonata','2550','1','3000','CLK001','RANGBHARIHOLI','70','100'),
('PI10303','Analogue','HMT','1350','1','1500','CLK001','OFF10','80','100'),
('PI10304','Analogue','Titan','3400','1','4000','CLK001','KHUSIWALIDIWALI','60','100'),
('PI10305','Digital','Timex','1500','1','2000','CLK001','SUMMER25','50','100'),

('PI10311','Digital','Reebok','2250','1','2500','CLK002','OFF10','90','100'),
('PI10312','Analogue','Maxima','1800','1','2000','CLK002','OFF10','50','100'),
('PI10313','Analogue','Titan','3750','1','5000','CLK002','SUMMER25','80','100'),
('PI10314','Analogue','Sonata','1530','1','1800','CLK002','KHUSIWALIDIWALI','30','100'),

('PI10321','Digital','Zoop','1080','1','1200','CLK003','OFF10','90','100'),
('PI10322','Analogue','Sonata','950','1','1000','CLK003','SUMMER5','50','100'),
('PI10323','Digital','Fastrack','1350','1','1500','CLK003','OFF10','80','100'),

('PI10601','Highlighter','Faber-castle','45','1','50','STN001','OFF10','90','100'),
('PI10602','Stapler','Kangaroo','95','1','100','STN001','WINTER5','50','100'),
('PI10603','Pen-stand','GAC','190','1','200','STN001','WINTER5','80','100'),
('PI10604','A4-paper','JK-Copier','570','1','600','STN001','SUMMER5','30','100'),

('PI10611','Long-Book','Camlin','90','1','100','STN002','OFF10','20','100'),
('PI10612','Notebook','Classmate','45','1','50','STN002','OFF10','50','100'),
('PI10613','Writing-board','FfUuNn','108','1','120','STN002','OFF10','70','100'),
('PI10614','Scrapbook','Navneet','57','1','60','STN002','WINTER5','80','100'),

('PI10621','Wax crayons','Camlin','18','1','20','STN003','OFF10','20','100'),
('PI10622','Fevicol','Pidilite','180','1','200','STN003','OFF10','50','100'),
('PI10623','Poster-colors','Camel','135','1','150','STN003','OFF10','70','100'),
('PI10624','Paper-cutter','Faber-castle','57','1','60','STN003','WINTER5','80','100'),

('PI10631','Gel-pen','Cello','90','10','100','STN004','OFF10','20','100'),
('PI10632','Ballpoint-pen','Flair','45','1','50','STN004','OFF10','50','100'),
('PI10633','Pencils','FfUuNn','45','1','50','STN004','OFF10','70','100'),
('PI10634','Eraser','Navneet','45','1','50','STN004','OFF10','80','100'),



('PI10401','Android phone','samsung','14450','1','15000','ELC001','KHUSIWALIDIWALI','20','20'),
('PI10404','Android phone','samsung','4450','1','5000','ELC001','KHUSIWALIDIWALI','20','20'),
('PI10402','windows','microsoft','7720','1','8000','ELC001','KHUSIWALIDIWALI','20','10'),
('PI10403','IPHONE','apple','38810','1','40000','ELC001','KHUSIWALIDIWALI','10','05'),

('PI10411','Android tablet','MI','12550','1','13000','ELC002','KHUSIWALIDIWALI','20','20'),
('PI10412','Android tablet','micromax','6450','1','7000','ELC002','KHUSIWALIDIWALI','20','20'),
('PI10414','windows','microsoft','9720','1','10000','ELC002','KHUSIWALIDIWALI','20','10'),
('PI10413','ipad','apple','48810','1','50000','ELC002','KHUSIWALIDIWALI','10','05'),

('PI10421','windows based','Acer','42550','1','43000','ELC003','KHUSIWALIDIWALI','20','20'),
('PI10422','windows based','Dell','36450','1','37000','ELC003','KHUSIWALIDIWALI','20','20'),
('PI10424','windows based','lenovo','29720','1','30000','ELC003','KHUSIWALIDIWALI','20','10'),
('PI10423','macbook','apple','47810','1','50000','ELC003','KHUSIWALIDIWALI','10','05'),


('PI10431','40 inch','sony','32550','1','33100','ELC004','KHUSIWALIDIWALI','20','20'),
('PI10432','32 inch','panasonic','26450','1','27200','ELC004','KHUSIWALIDIWALI','20','20'),
('PI10434','premium tv','vu','39720','1','45000','ELC004','KHUSIWALIDIWALI','20','10'),
('PI10433','32 inch','samsung','38810','1','42300','ELC004','KHUSIWALIDIWALI','10','05'),

('PI10441','home theatre','sony','22550','1','23100','ELC005','KHUSIWALIDIWALI','20','20'),
('PI10442','bluetooth speaker','philips','1450','1','1300','ELC005','KHUSIWALIDIWALI','20','20'),
('PI10444','soundbars','philips','19720','1','21000','ELC005','KHUSIWALIDIWALI','20','10'),
('PI10443','ipods','apple','18810','1','19300','ELC005','KHUSIWALIDIWALI','10','05'),

('PI10501','cutlery','uberlyfe','550','1','600','DNG001','KHUSIWALIDIWALI','200','200'),
('PI10502','glasses','godskitchen','450','1','500','DNG001','KHUSIWALIDIWALI','200','120'),
('PI10503','dishware','planet','720','1','800','DNG001','KHUSIWALIDIWALI','200','100'),
('PI10504','trays','woogor','310','1','400','DNG001','KHUSIWALIDIWALI','100','305'),

('PI10511','Jars & Containers ','cello','750','1','800','DNG002','KHUSIWALIDIWALI','120','52'),
('PI10512','lunch boxes','blossoms','250','1','300','DNG002','KHUSIWALIDIWALI','120','20'),
('PI10513','kitchen racks','generic','1020','1','1100','DNG002','KHUSIWALIDIWALI','220','110'),
('PI10514','produce storage bags','bagathon india','610','1','700','DNG002','KHUSIWALIDIWALI','100','105'),

('PI10521','juicer','bajaj','1750','1','1850','DNG003','KHUSIWALIDIWALI','30','12'),
('PI10522','grinder','maharaj','2250','1','2350','DNG003','KHUSIWALIDIWALI','20','10'),
('PI10523','vegetable cutter','prestige','1120','1','1200','DNG003','KHUSIWALIDIWALI','40','10'),
('PI10524','fruit chooper','ganesh','610','1','700','DNG003','KHUSIWALIDIWALI','40','15'),


('PI10531','cooking induction','prystine','1450','1','1550','DNG004','KHUSIWALIDIWALI','30','12'),
('PI10532','presssure cooker','prestige','1250','1','1350','DNG004','KHUSIWALIDIWALI','20','10'),
('PI10533','cooking pots','king','420','1','500','DNG004','KHUSIWALIDIWALI','40','10'),
('PI10534','casserole set','pristine','1010','1','1100','DNG004','KHUSIWALIDIWALI','40','15');



INSERT INTO Buys VALUES('PI10531','AAA001','1','1550'),
('PI10511','AAA001','1','800'),
('PI10602','AAA001','1','100'),

('PI10441','AAA002','1','2310'),
('PI10522','AAA002','1','2350'),
('PI10532','AAA002','1','1350'),
('PI10432','AAA002','1','27200'),


('PI10441','AAA003','2','2310'),
('PI10522','AAA003','2','2350'),
('PI10444','AAA003','1','21000'),
('PI10431','AAA003','1','33100'),

('PI10511','AAB002','4','800'),
('PI10533','AAB002','3','500'),
('PI10532','AAB002','1','1350'),
('PI10432','AAB002','1','27200'),


('PI10313','AAB001','1','5000'),
('PI10203','AAB001','1','2000'),
('PI10121','AAB001','1','1400'),
('PI10433','AAB001','1','42300'),

('PI10532','AAH001','2','1350'),
('PI10533','AAH001','2','500'),
('PI10101','AAH001','2','400'),

('PI10041','AAC002','5','100'),
('PI10534','AAC002','2','1100'),
('PI10304','AAC002','2','4000'),

('PI10111','AAD002','2','1400'),
('PI10534','AAD002','2','1100'),
('PI10304','AAD002','2','4000'),

('PI10112','AAD001','2','1300'),
('PI10534','AAD001','1','1100'),
('PI10301','AAD001','1','5000'),

('PI10511','AAD003','2','800'),
('PI10441','AAD003','2','2310'),
('PI10304','AAD003','2','4000'),

('PI10121','AAE002','2','1400'),
('PI10122','AAE002','2','1300'),
('PI10304','AAE002','2','4000'),

('PI10411','AAE001','1','13000'),
('PI10442','AAE001','1','1450'),
('PI10301','AAE001','1','5000'),

('PI10121','AAF002','1','1400'),
('PI10122','AAF002','1','1300'),
('PI10304','AAF002','1','4000'),
('PI10421','AAF001','1','43000'),
('PI10442','AAF001','1','1450'),
('PI10301','AAF001','1','5000'),
('PI10121','AAG002','1','1400'),
('PI10442','AAG001','1','1450'),
('PI10301','AAG001','1','5000');

INSERT INTO ReturnSlip VALUES('SL001','AAB001','PI10203','1','2015-03-06'),
('SL002','AAD001','PI10112','1','2017-01-05'),
('SL003','AAC001','PI10041','2','2014-02-20'),
('SL004','AAH001','PI10532','1','2016-04-01'),
('SL005','AAD002','PI10112','1','2015-01-18');



INSERT INTO Feedback VALUES('RV001','Pears shop is expire','2','2021-05-03','CTM00002','AAG002'),
('RV002','Quality is not good','3','2021-01-15','CTM00013','AAF002'),
('RV003','vegitable is bad','2','2022-02-15','CTM00011','AAH001'),
('RV004','Sony speakers is fake','1','2022-02-15','CTM00014','AAC002');