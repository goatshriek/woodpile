!include <win32.mak>


# directory definitions
INCDIR = $(BASEDIR)\..\..\include
LIBDIR = $(BASEDIR)\..\..\lib
OUTDIR = $(BASEDIR)\build
SRCDIR = $(BASEDIR)\..\..\src
TESTDIR = $(BASEDIR)\..\..\test


# all target
all: $(OUTDIR)\woodpile.dll


# directory creation
$(OUTDIR):
  if not exist "$(OUTDIR)\$(NULL)" mkdir $(OUTDIR)
  if not exist "$(OUTDIR)\lib\$(NULL)" mkdir $(OUTDIR)\lib
  if not exist "$(OUTDIR)\src\$(NULL)" mkdir $(OUTDIR)\src
  if not exist "$(OUTDIR)\src\list\$(NULL)" mkdir $(OUTDIR)\src\list
  if not exist "$(OUTDIR)\test\$(NULL)" mkdir $(OUTDIR)\test
  if not exist "$(OUTDIR)\test\function\$(NULL)" mkdir $(OUTDIR)\test\function
  if not exist "$(OUTDIR)\test\function\list\$(NULL)" mkdir $(OUTDIR)\test\function\list
  if not exist "$(OUTDIR)\test\helper\$(NULL)" mkdir $(OUTDIR)\test\helper


# build options
WOODPILECFLAGS = $(cflags) $(cvarsdll) $(cdebug) /nologo /I $(BASEDIR) /I $(INCDIR)
WOODPILELFLAGS = $(linkdebug) /nologo
WOODPILEDLLLFLAGS = $(linkdebug) $(dlllflags) /nologo


# woodpile object files
WOODPILEOBJS = $(OUTDIR)\lib\str.obj \
               $(OUTDIR)\src\list.obj \
               $(OUTDIR)\src\list\const_iterator.obj \
               $(OUTDIR)\src\list\iterator.obj \
               $(OUTDIR)\src\queue.obj \
               $(OUTDIR)\src\stack.obj

$(OUTDIR)\lib\str.obj: $(OUTDIR) $(LIBDIR)\str.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\lib\ /Fd$(OUTDIR)\lib.pdb $(LIBDIR)\str.c

$(OUTDIR)\src\list.obj: $(OUTDIR) $(SRCDIR)\list.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\src\ /Fd$(OUTDIR)\woodpile.pdb $(SRCDIR)\list.c
  
$(OUTDIR)\src\list\const_iterator.obj: $(OUTDIR) $(SRCDIR)\list\const_iterator.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\src\list\ /Fd$(OUTDIR)\woodpile.pdb $(SRCDIR)\list\const_iterator.c
  
$(OUTDIR)\src\list\iterator.obj: $(OUTDIR) $(SRCDIR)\list\iterator.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\src\list\ /Fd$(OUTDIR)\woodpile.pdb $(SRCDIR)\list\iterator.c

$(OUTDIR)\src\queue.obj: $(OUTDIR) $(SRCDIR)\queue.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\src\ /Fd$(OUTDIR)\woodpile.pdb $(SRCDIR)\queue.c

$(OUTDIR)\src\stack.obj: $(OUTDIR) $(SRCDIR)\stack.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\src\ /Fd$(OUTDIR)\woodpile.pdb $(SRCDIR)\stack.c

  
# test helper object files
HELPEROBJS = $(OUTDIR)\lib\str.obj $(OUTDIR)\test\helper\builder.obj $(OUTDIR)\test\helper\fixture.obj  

$(OUTDIR)\test\helper\builder.obj: $(OUTDIR) $(TESTDIR)\helper\builder.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\test\helper\ /Fd$(OUTDIR)\helper.pdb $(TESTDIR)\helper\builder.c
    
$(OUTDIR)\test\helper\fixture.obj: $(OUTDIR) $(TESTDIR)\helper\fixture.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\test\helper\ /Fd$(OUTDIR)\helper.pdb $(TESTDIR)\helper\fixture.c


# libraries
$(OUTDIR)\woodpile.dll: $(WOODPILEOBJS)
  $(link) $(WOODPILEDLLLFLAGS) /out:$(OUTDIR)\woodpile.dll /DEF:$(BASEDIR)\woodpile.def $(WOODPILEOBJS)

$(OUTDIR)\helper.dll: $(OUTDIR)\woodpile.dll $(HELPEROBJS)
  $(link) $(WOODPILEDLLLFLAGS) /out:$(OUTDIR)\helper.dll /DEF:$(BASEDIR)\helper.def $(OUTDIR)\woodpile.lib $(HELPEROBJS)
  

# test executables
TESTEXES = $(OUTDIR)\test\function\list_suite.exe \
           $(OUTDIR)\test\function\list\const_iterator_suite.exe \
           $(OUTDIR)\test\function\list\iterator_suite.exe \
           $(OUTDIR)\test\function\queue_suite.exe \
           $(OUTDIR)\test\function\stack_suite.exe

$(OUTDIR)\test\function\list_suite.exe: $(OUTDIR)\helper.dll $(OUTDIR)\test\function\list_suite.obj $(OUTDIR)\lib\str.obj
  $(link) $(WOODPILELFLAGS) /out:$(OUTDIR)\test\function\list_suite.exe $(OUTDIR)\woodpile.lib $(OUTDIR)\helper.lib $(OUTDIR)\test\function\list_suite.obj $(OUTDIR)\lib\str.obj

$(OUTDIR)\test\function\list\const_iterator_suite.exe: $(OUTDIR)\helper.dll $(OUTDIR)\test\function\list\const_iterator_suite.obj
  $(link) $(WOODPILELFLAGS) /out:$(OUTDIR)\test\function\list\const_iterator_suite.exe $(OUTDIR)\woodpile.lib $(OUTDIR)\helper.lib  $(OUTDIR)\test\function\list\const_iterator_suite.obj

$(OUTDIR)\test\function\list\iterator_suite.exe: $(OUTDIR)\helper.dll $(OUTDIR)\test\function\list\iterator_suite.obj
  $(link) $(WOODPILELFLAGS) /out:$(OUTDIR)\test\function\list\iterator_suite.exe $(OUTDIR)\woodpile.lib $(OUTDIR)\helper.lib $(OUTDIR)\test\function\list\iterator_suite.obj

$(OUTDIR)\test\function\queue_suite.exe: $(OUTDIR)\helper.dll $(OUTDIR)\test\function\queue_suite.obj
  $(link) $(WOODPILELFLAGS) /out:$(OUTDIR)\test\function\queue_suite.exe $(OUTDIR)\woodpile.lib $(OUTDIR)\helper.lib $(OUTDIR)\test\function\queue_suite.obj

$(OUTDIR)\test\function\stack_suite.exe: $(OUTDIR)\helper.dll $(OUTDIR)\test\function\stack_suite.obj
  $(link) $(WOODPILELFLAGS) /out:$(OUTDIR)\test\function\stack_suite.exe $(OUTDIR)\woodpile.lib $(OUTDIR)\helper.lib $(OUTDIR)\test\function\stack_suite.obj


# test target
check: $(TESTEXES)
  cd $(OUTDIR)
  $(OUTDIR)\test\function\list_suite.exe > $(OUTDIR)\test-suite.log
  $(OUTDIR)\test\function\list\const_iterator_suite.exe >> $(OUTDIR)\test-suite.log
  $(OUTDIR)\test\function\list\iterator_suite.exe >> $(OUTDIR)\test-suite.log
  $(OUTDIR)\test\function\queue_suite.exe >> $(OUTDIR)\test-suite.log
  $(OUTDIR)\test\function\stack_suite.exe >> $(OUTDIR)\test-suite.log
  cd $(BASEDIR)
  

# test object files
$(OUTDIR)\test\function\list_suite.obj: $(OUTDIR) $(TESTDIR)\function\list_suite.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\test\function\ /Fd$(OUTDIR)\test\function\list_suite.pdb $(TESTDIR)\function\list_suite.c
  
$(OUTDIR)\test\function\list\const_iterator_suite.obj: $(OUTDIR) $(TESTDIR)\function\list\const_iterator_suite.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\test\function\list\ /Fd$(OUTDIR)\test\function\list\const_iterator.pdb $(TESTDIR)\function\list\const_iterator_suite.c
  
$(OUTDIR)\test\function\list\iterator_suite.obj: $(OUTDIR) $(TESTDIR)\function\list\iterator_suite.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\test\function\list\ /Fd$(OUTDIR)\test\function\list\iterator.pdb $(TESTDIR)\function\list\iterator_suite.c
  
$(OUTDIR)\test\function\queue_suite.obj: $(OUTDIR) $(TESTDIR)\function\queue_suite.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\test\function\ /Fd$(OUTDIR)\test\function\queue_suite.pdb $(TESTDIR)\function\queue_suite.c
  
$(OUTDIR)\test\function\stack_suite.obj: $(OUTDIR) $(TESTDIR)\function\stack_suite.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\test\function\ /Fd$(OUTDIR)\test\function\stack_suite.pdb $(TESTDIR)\function\stack_suite.c
  
clean:
  $(CLEANUP)