# BinaryAnalyzer

BinaryAnalyzer, C++ ve Nesne Yönelimli Programlama (OOP) kullanılarak geliştirilmiş savunma odaklı statik malware analiz aracıdır.

Program, PE (Windows EXE/DLL) ve ELF (Linux executable) dosyalarını analiz ederek dosya yapısını, section bilgilerini, entry point adresini ve şüpheli API kullanımlarını tespit eder.

Bu araç yalnızca statik analiz yapar ve dosyayı çalıştırmaz. Bu nedenle güvenli ve defensive cybersecurity yaklaşımına uygundur.

---

# Özellikler

- PE (Windows EXE/DLL) analizi
- ELF (Linux executable) analizi
- Section analizi
- Entry Point tespiti
- Machine Type analizi
- Malware risk skorlama sistemi
- Şüpheli API tespiti
- Static binary analysis
- Command-line desteği
- OOP mimarisi

---

# Desteklenen Şüpheli API’ler

- VirtualAlloc
- VirtualProtect
- LoadLibraryA
- LoadLibraryW
- CreateRemoteThread
- WriteProcessMemory

---

# Proje Mimarisi

```text
BinaryAnalyzer/
│
├── main.cpp
├── BinaryFile.h
├── BinaryFile.cpp
├── IParser.h
├── PEParser.h
├── PEParser.cpp
├── ELFParser.h
├── ELFParser.cpp
├── MalwareAnalyzer.h
├── MalwareAnalyzer.cpp
└── README.md
Kullanım
BinaryAnalyzer.exe sample.exe

Örnek:

BinaryAnalyzer.exe C:\Windows\System32\notepad.exe
Örnek Çıktı
Dosya tipi: PE / Windows EXE-DLL
Machine Type: 0x8664
Section sayisi: 8

Suspicious API Detected:
- VirtualAlloc
- LoadLibraryA

Risk Skoru: 55
Risk Seviyesi: Orta
Malware Risk Skorlama Sistemi
Özellik	Risk Puanı
VirtualAlloc	+20
VirtualProtect	+20
LoadLibrary	+15
CreateRemoteThread	+30
WriteProcessMemory	+30
UPX Section	+25
Executable Section	+10
Kullanılan Teknolojiler
C++
Object-Oriented Programming (OOP)
Static Malware Analysis
PE File Format
ELF File Format
Binary Parsing
Projenin Amacı

Bu projede amaç, binary dosyaların yapısını analiz eden ve temel malware davranışlarını tespit eden bir güvenlik aracı geliştirmektir.

Program:

Dosya formatını tespit eder
Section bilgilerini çıkarır
Entry Point adresini bulur
Şüpheli API kullanımını analiz eder
Risk skoru üretir

Bu sistem defensive cybersecurity yaklaşımına uygundur çünkü analiz edilen dosya çalıştırılmaz.

Eğitim Amaçlı Kullanım

Bu proje yalnızca eğitim ve savunma amaçlı geliştirilmiştir.

Program zararlı yazılım üretmez, çalıştırmaz veya yaymaz.
Sadece statik analiz gerçekleştirir.