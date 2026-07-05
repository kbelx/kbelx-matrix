## 1 - CONTEXTO
criar as subpastas baseando-se no arquivo README.md ( especificamente, o capítulo número 3) conforme o nome do projeto é permitido.

## 2 - STACK
- o trabalho deve ocorrer em arquivo.cpp
- main.cpp que criará
- olhar o README.md para fins de intruções
- olhar doc/Microsoft_Visio/pdf/ para fins de referência

## 3 - REQUISITOS
o projeto deve ter as seguintes subpastas:
- **01_AUDIO_FILES**: contendo as pastas _RECORD_ e _SAMPLES_
- 03_SESSION_FILES: contendo as pastas *PRODUCER_SESSION, MIX_SESSION* e *MASTER_SESSION*
- 03_BOUNCED_FILES: contendo as pastas *STEMS, MIXING_EXPORTS, MASTERING_EXPORTS, INSTRUMENTAL* e *OBSOLETE*
- metadados.txt

o metadado deve gerar assim:
```txt
============================================================
					METADADOS DO PROJETO 
============================================================

TÍTULO:      [Nome da Obra / Álbum / Single]
AUTOR(ES):   [Compositor, Produtor, Artistas]
GÊNERO:      [Estilo Musical]
DATA:        [DD/MM/AAAA]

------------------------------------------------------------
COMENTÁRIOS E NOTAS:
   > 
   > 
   > 

------------------------------------------------------------
SPECS TÉCNICAS:
   Sample Rate: [ex: 48kHz] | Bit Depth: [ex: 24-bit]
   BPM: [000]               | Key: [ex: Am]
============================================================
```