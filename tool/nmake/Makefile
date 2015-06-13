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
  if not exist "$(OUTDIR)\src\dynamic\$(NULL)" mkdir $(OUTDIR)\src\dynamic
  if not exist "$(OUTDIR)\src\dynamic\list\$(NULL)" mkdir $(OUTDIR)\src\dynamic\list
  if not exist "$(OUTDIR)\src\static\$(NULL)" mkdir $(OUTDIR)\src\static
  if not exist "$(OUTDIR)\test\$(NULL)" mkdir $(OUTDIR)\test
  if not exist "$(OUTDIR)\test\function\$(NULL)" mkdir $(OUTDIR)\test\function
  if not exist "$(OUTDIR)\test\function\dynamic\$(NULL)" mkdir $(OUTDIR)\test\function\dynamic
  if not exist "$(OUTDIR)\test\function\dynamic\list\$(NULL)" mkdir $(OUTDIR)\test\function\dynamic\list
  if not exist "$(OUTDIR)\test\function\static\$(NULL)" mkdir $(OUTDIR)\test\function\static
  if not exist "$(OUTDIR)\test\helper\$(NULL)" mkdir $(OUTDIR)\test\helper


# build options
WOODPILECFLAGS = $(cflags) $(cvarsdll) $(cdebug) /nologo /I $(BASEDIR) /I $(INCDIR)
WOODPILELFLAGS = $(linkdebug) /nologo
WOODPILEDLLLFLAGS = $(linkdebug) $(dlllflags) /nologo


# woodpile object files
WOODPILEOBJS = $(OUTDIR)\lib\str.obj \
               $(OUTDIR)\src\dynamic\list.obj \
               $(OUTDIR)\src\dynamic\list\const_iterator.obj \
               $(OUTDIR)\src\dynamic\list\iterator.obj \
               $(OUTDIR)\src\static\queue.obj \
               $(OUTDIR)\src\static\stack.obj

$(OUTDIR)\lib\str.obj: $(OUTDIR) $(LIBDIR)\str.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\lib\ /Fd$(OUTDIR)\lib.pdb $(LIBDIR)\str.c

$(OUTDIR)\src\dynamic\list.obj: $(OUTDIR) $(SRCDIR)\dynamic\list.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\src\dynamic\ /Fd$(OUTDIR)\woodpile.pdb $(SRCDIR)\dynamic\list.c
  
$(OUTDIR)\src\dynamic\list\const_iterator.obj: $(OUTDIR) $(SRCDIR)\dynamic\list\const_iterator.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\src\dynamic\list\ /Fd$(OUTDIR)\woodpile.pdb $(SRCDIR)\dynamic\list\const_iterator.c
  
$(OUTDIR)\src\dynamic\list\iterator.obj: $(OUTDIR) $(SRCDIR)\dynamic\list\iterator.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\src\dynamic\list\ /Fd$(OUTDIR)\woodpile.pdb $(SRCDIR)\dynamic\list\iterator.c

$(OUTDIR)\src\static\queue.obj: $(OUTDIR) $(SRCDIR)\static\queue.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\src\static\ /Fd$(OUTDIR)\woodpile.pdb $(SRCDIR)\static\queue.c

$(OUTDIR)\src\static\stack.obj: $(OUTDIR) $(SRCDIR)\static\stack.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\src\static\ /Fd$(OUTDIR)\woodpile.pdb $(SRCDIR)\static\stack.c

  
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
TESTEXES = $(OUTDIR)\test\function\dynamic\list_suite.exe \
           $(OUTDIR)\test\function\dynamic\list\const_iterator_suite.exe \
           $(OUTDIR)\test\function\dynamic\list\iterator_suite.exe \
           $(OUTDIR)\test\function\static\queue_suite.exe \
           $(OUTDIR)\test\function\static\stack_suite.exe

$(OUTDIR)\test\function\dynamic\list_suite.exe: $(OUTDIR)\helper.dll $(OUTDIR)\test\function\dynamic\list_suite.obj $(OUTDIR)\lib\str.obj
  $(link) $(WOODPILELFLAGS) /out:$(OUTDIR)\test\function\dynamic\list_suite.exe $(OUTDIR)\woodpile.lib $(OUTDIR)\helper.lib $(OUTDIR)\test\function\dynamic\list_suite.obj $(OUTDIR)\lib\str.obj

$(OUTDIR)\test\function\dynamic\list\const_iterator_suite.exe: $(OUTDIR)\helper.dll $(OUTDIR)\test\function\dynamic\list\const_iterator_suite.obj
  $(link) $(WOODPILELFLAGS) /out:$(OUTDIR)\test\function\dynamic\list\const_iterator_suite.exe $(OUTDIR)\woodpile.lib $(OUTDIR)\helper.lib  $(OUTDIR)\test\function\dynamic\list\const_iterator_suite.obj

$(OUTDIR)\test\function\dynamic\list\iterator_suite.exe: $(OUTDIR)\helper.dll $(OUTDIR)\test\function\dynamic\list\iterator_suite.obj
  $(link) $(WOODPILELFLAGS) /out:$(OUTDIR)\test\function\dynamic\list\iterator_suite.exe $(OUTDIR)\woodpile.lib $(OUTDIR)\helper.lib $(OUTDIR)\test\function\dynamic\list\iterator_suite.obj

$(OUTDIR)\test\function\static\queue_suite.exe: $(OUTDIR)\helper.dll $(OUTDIR)\test\function\static\queue_suite.obj
  $(link) $(WOODPILELFLAGS) /out:$(OUTDIR)\test\function\static\queue_suite.exe $(OUTDIR)\woodpile.lib $(OUTDIR)\helper.lib $(OUTDIR)\test\function\static\queue_suite.obj

$(OUTDIR)\test\function\static\stack_suite.exe: $(OUTDIR)\helper.dll $(OUTDIR)\test\function\static\stack_suite.obj
  $(link) $(WOODPILELFLAGS) /out:$(OUTDIR)\test\function\static\stack_suite.exe $(OUTDIR)\woodpile.lib $(OUTDIR)\helper.lib $(OUTDIR)\test\function\static\stack_suite.obj


# test target
check: $(TESTEXES)
  cd $(OUTDIR)
  $(OUTDIR)\test\function\dynamic\list_suite.exe > $(OUTDIR)\test-suite.log
  $(OUTDIR)\test\function\dynamic\list\const_iterator_suite.exe >> $(OUTDIR)\test-suite.log
  $(OUTDIR)\test\function\dynamic\list\iterator_suite.exe >> $(OUTDIR)\test-suite.log
  $(OUTDIR)\test\function\static\queue_suite.exe >> $(OUTDIR)\test-suite.log
  $(OUTDIR)\test\function\static\stack_suite.exe >> $(OUTDIR)\test-suite.log
  cd $(BASEDIR)
  

# test object files
$(OUTDIR)\test\function\dynamic\list_suite.obj: $(OUTDIR) $(TESTDIR)\function\dynamic\list_suite.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\test\function\dynamic\ /Fd$(OUTDIR)\test\function\dynamic\list_suite.pdb $(TESTDIR)\function\dynamic\list_suite.c
  
$(OUTDIR)\test\function\dynamic\list\const_iterator_suite.obj: $(OUTDIR) $(TESTDIR)\function\dynamic\list\const_iterator_suite.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\test\function\dynamic\list\ /Fd$(OUTDIR)\test\function\dynamic\list\const_iterator.pdb $(TESTDIR)\function\dynamic\list\const_iterator_suite.c
  
$(OUTDIR)\test\function\dynamic\list\iterator_suite.obj: $(OUTDIR) $(TESTDIR)\function\dynamic\list\iterator_suite.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\test\function\dynamic\list\ /Fd$(OUTDIR)\test\function\dynamic\list\iterator.pdb $(TESTDIR)\function\dynamic\list\iterator_suite.c
  
$(OUTDIR)\test\function\static\queue_suite.obj: $(OUTDIR) $(TESTDIR)\function\static\queue_suite.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\test\function\static\ /Fd$(OUTDIR)\test\function\static\queue_suite.pdb $(TESTDIR)\function\static\queue_suite.c
  
$(OUTDIR)\test\function\static\stack_suite.obj: $(OUTDIR) $(TESTDIR)\function\static\stack_suite.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\test\function\static\ /Fd$(OUTDIR)\test\function\static\stack_suite.pdb $(TESTDIR)\function\static\stack_suite.c
  
clean:
  $(CLEANUP)
