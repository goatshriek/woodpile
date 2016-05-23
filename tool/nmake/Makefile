!include <win32.mak>

!ifndef BASEDIR
BASEDIR = .
!endif


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
  if not exist "$(OUTDIR)\src\dynamic\tree\$(NULL)" mkdir $(OUTDIR)\src\dynamic\tree
  if not exist "$(OUTDIR)\src\dynamic\tree\splay\$(NULL)" mkdir $(OUTDIR)\src\dynamic\tree\splay
  if not exist "$(OUTDIR)\src\static\$(NULL)" mkdir $(OUTDIR)\src\static
  if not exist "$(OUTDIR)\test\$(NULL)" mkdir $(OUTDIR)\test
  if not exist "$(OUTDIR)\test\function\$(NULL)" mkdir $(OUTDIR)\test\function
  if not exist "$(OUTDIR)\test\function\dynamic\$(NULL)" mkdir $(OUTDIR)\test\function\dynamic
  if not exist "$(OUTDIR)\test\function\dynamic\list\$(NULL)" mkdir $(OUTDIR)\test\function\dynamic\list
  if not exist "$(OUTDIR)\test\function\dynamic\tree\$(NULL)" mkdir $(OUTDIR)\test\function\dynamic\tree
  if not exist "$(OUTDIR)\test\function\dynamic\tree\splay\$(NULL)" mkdir $(OUTDIR)\test\function\dynamic\tree\splay
  if not exist "$(OUTDIR)\test\function\static\$(NULL)" mkdir $(OUTDIR)\test\function\static
  if not exist "$(OUTDIR)\test\helper\$(NULL)" mkdir $(OUTDIR)\test\helper


# build options
WOODPILECFLAGS = $(cflags) $(cvarsdll) $(cdebug) /nologo /I $(BASEDIR) /I $(INCDIR)
WOODPILELFLAGS = $(linkdebug) /nologo
WOODPILEDLLLFLAGS = $(linkdebug) $(dlllflags) /nologo


# woodpile object files
WOODPILEOBJS = $(OUTDIR)\lib\str.obj \
               $(OUTDIR)\src\comparator.obj \
               $(OUTDIR)\src\dynamic\list.obj \
               $(OUTDIR)\src\dynamic\list\const_iterator.obj \
               $(OUTDIR)\src\dynamic\list\iterator.obj \
               $(OUTDIR)\src\dynamic\tree\splay.obj \
               $(OUTDIR)\src\dynamic\tree\splay\const_iterator.obj \
               $(OUTDIR)\src\dynamic\tree\splay\iterator.obj \
               $(OUTDIR)\src\hasher.obj \
               $(OUTDIR)\src\static\hash.obj \
               $(OUTDIR)\src\static\queue.obj \
               $(OUTDIR)\src\static\stack.obj

$(OUTDIR)\lib\str.obj: $(OUTDIR) $(LIBDIR)\str.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\lib\ /Fd$(OUTDIR)\lib.pdb $(LIBDIR)\str.c

$(OUTDIR)\src\comparator.obj: $(OUTDIR) $(SRCDIR)\comparator.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\src\ /Fd$(OUTDIR)\woodpile.pdb $(SRCDIR)\comparator.c

$(OUTDIR)\src\dynamic\list.obj: $(OUTDIR) $(SRCDIR)\dynamic\list.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\src\dynamic\ /Fd$(OUTDIR)\woodpile.pdb $(SRCDIR)\dynamic\list.c
  
$(OUTDIR)\src\dynamic\list\const_iterator.obj: $(OUTDIR) $(SRCDIR)\dynamic\list\const_iterator.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\src\dynamic\list\ /Fd$(OUTDIR)\woodpile.pdb $(SRCDIR)\dynamic\list\const_iterator.c
  
$(OUTDIR)\src\dynamic\list\iterator.obj: $(OUTDIR) $(SRCDIR)\dynamic\list\iterator.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\src\dynamic\list\ /Fd$(OUTDIR)\woodpile.pdb $(SRCDIR)\dynamic\list\iterator.c
  
$(OUTDIR)\src\dynamic\tree\splay.obj: $(OUTDIR) $(SRCDIR)\dynamic\tree\splay.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\src\dynamic\tree\ /Fd$(OUTDIR)\woodpile.pdb $(SRCDIR)\dynamic\tree\splay.c
  
$(OUTDIR)\src\dynamic\tree\splay\const_iterator.obj: $(OUTDIR) $(SRCDIR)\dynamic\tree\splay\const_iterator.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\src\dynamic\tree\splay\ /Fd$(OUTDIR)\woodpile.pdb $(SRCDIR)\dynamic\tree\splay\const_iterator.c
  
$(OUTDIR)\src\dynamic\tree\splay\iterator.obj: $(OUTDIR) $(SRCDIR)\dynamic\tree\splay\iterator.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\src\dynamic\tree\splay\ /Fd$(OUTDIR)\woodpile.pdb $(SRCDIR)\dynamic\tree\splay\iterator.c

$(OUTDIR)\src\hasher.obj: $(OUTDIR) $(SRCDIR)\hasher.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\src\ /Fd$(OUTDIR)\woodpile.pdb $(SRCDIR)\hasher.c

$(OUTDIR)\src\static\hash.obj: $(OUTDIR) $(SRCDIR)\static\hash.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\src\static\ /Fd$(OUTDIR)\woodpile.pdb $(SRCDIR)\static\hash.c

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
           $(OUTDIR)\test\function\dynamic\tree\splay_suite.exe \
           $(OUTDIR)\test\function\dynamic\tree\splay\const_iterator_suite.exe \
           $(OUTDIR)\test\function\dynamic\tree\splay\iterator_suite.exe \
           $(OUTDIR)\test\function\static\hash_suite.exe \
           $(OUTDIR)\test\function\static\queue_suite.exe \
           $(OUTDIR)\test\function\static\stack_suite.exe

$(OUTDIR)\test\function\dynamic\list_suite.exe: $(OUTDIR)\helper.dll $(OUTDIR)\test\function\dynamic\list_suite.obj $(OUTDIR)\lib\str.obj $(OUTDIR)\test\function\dynamic\list_common.obj
  $(link) $(WOODPILELFLAGS) \
          /out:$(OUTDIR)\test\function\dynamic\list_suite.exe \
          $(OUTDIR)\woodpile.lib \
          $(OUTDIR)\helper.lib \
          $(OUTDIR)\test\function\dynamic\list_suite.obj \
          $(OUTDIR)\test\function\dynamic\list_common.obj \
          $(OUTDIR)\lib\str.obj

$(OUTDIR)\test\function\dynamic\list\const_iterator_suite.exe: $(OUTDIR)\helper.dll $(OUTDIR)\test\function\dynamic\list\const_iterator_suite.obj
  $(link) $(WOODPILELFLAGS) /out:$(OUTDIR)\test\function\dynamic\list\const_iterator_suite.exe $(OUTDIR)\woodpile.lib $(OUTDIR)\helper.lib  $(OUTDIR)\test\function\dynamic\list\const_iterator_suite.obj

$(OUTDIR)\test\function\dynamic\list\iterator_suite.exe: $(OUTDIR)\helper.dll $(OUTDIR)\test\function\dynamic\list\iterator_suite.obj $(OUTDIR)\test\function\dynamic\list\iterator_common.obj
  $(link) $(WOODPILELFLAGS) \
          /out:$(OUTDIR)\test\function\dynamic\list\iterator_suite.exe \
          $(OUTDIR)\woodpile.lib \
          $(OUTDIR)\helper.lib \
          $(OUTDIR)\test\function\dynamic\list\iterator_suite.obj \
          $(OUTDIR)\test\function\dynamic\list\iterator_common.obj

$(OUTDIR)\test\function\dynamic\tree\splay_suite.exe: $(OUTDIR)\helper.dll $(OUTDIR)\test\function\dynamic\tree\splay_suite.obj $(OUTDIR)\lib\str.obj $(OUTDIR)\test\function\dynamic\tree\splay_common.obj
  $(link) $(WOODPILELFLAGS) \
          /out:$(OUTDIR)\test\function\dynamic\tree\splay_suite.exe \
          $(OUTDIR)\woodpile.lib \
          $(OUTDIR)\helper.lib \
          $(OUTDIR)\test\function\dynamic\tree\splay_suite.obj \
          $(OUTDIR)\test\function\dynamic\tree\splay_common.obj \
          $(OUTDIR)\lib\str.obj

$(OUTDIR)\test\function\dynamic\tree\splay\const_iterator_suite.exe: $(OUTDIR)\helper.dll $(OUTDIR)\test\function\dynamic\tree\splay\const_iterator_suite.obj
  $(link) $(WOODPILELFLAGS) /out:$(OUTDIR)\test\function\dynamic\tree\splay\const_iterator_suite.exe $(OUTDIR)\woodpile.lib $(OUTDIR)\helper.lib $(OUTDIR)\test\function\dynamic\tree\splay\const_iterator_suite.obj

$(OUTDIR)\test\function\dynamic\tree\splay\iterator_suite.exe: $(OUTDIR)\helper.dll $(OUTDIR)\test\function\dynamic\tree\splay\iterator_suite.obj
  $(link) $(WOODPILELFLAGS) /out:$(OUTDIR)\test\function\dynamic\tree\splay\iterator_suite.exe $(OUTDIR)\woodpile.lib $(OUTDIR)\helper.lib $(OUTDIR)\test\function\dynamic\tree\splay\iterator_suite.obj

$(OUTDIR)\test\function\static\hash_suite.exe: $(OUTDIR)\helper.dll $(OUTDIR)\test\function\static\hash_suite.obj $(OUTDIR)\test\function\static\hash_common.obj
  $(link) $(WOODPILELFLAGS) /out:$(OUTDIR)\test\function\static\hash_suite.exe $(OUTDIR)\woodpile.lib $(OUTDIR)\helper.lib $(OUTDIR)\test\function\static\hash_suite.obj $(OUTDIR)\test\function\static\hash_common.obj

$(OUTDIR)\test\function\static\queue_suite.exe: $(OUTDIR)\helper.dll $(OUTDIR)\test\function\static\queue_suite.obj $(OUTDIR)\test\function\static\queue_common.obj
  $(link) $(WOODPILELFLAGS) \
          /out:$(OUTDIR)\test\function\static\queue_suite.exe \
          $(OUTDIR)\woodpile.lib \
          $(OUTDIR)\helper.lib \
          $(OUTDIR)\test\function\static\queue_suite.obj \
          $(OUTDIR)\test\function\static\queue_common.obj

$(OUTDIR)\test\function\static\stack_suite.exe: $(OUTDIR)\helper.dll $(OUTDIR)\test\function\static\stack_suite.obj
  $(link) $(WOODPILELFLAGS) /out:$(OUTDIR)\test\function\static\stack_suite.exe $(OUTDIR)\woodpile.lib $(OUTDIR)\helper.lib $(OUTDIR)\test\function\static\stack_suite.obj


# test target
check: $(TESTEXES)
  cd $(OUTDIR)
  test\function\dynamic\list_suite.exe > test-suite.log
  test\function\dynamic\list\const_iterator_suite.exe >> test-suite.log
  test\function\dynamic\list\iterator_suite.exe >> test-suite.log
  test\function\dynamic\tree\splay_suite.exe >> test-suite.log
  test\function\dynamic\tree\splay\const_iterator_suite.exe >> test-suite.log
  test\function\dynamic\tree\splay\iterator_suite.exe >> test-suite.log
  test\function\static\hash_suite.exe >> test-suite.log
  test\function\static\queue_suite.exe >> test-suite.log
  test\function\static\stack_suite.exe >> test-suite.log
  cd $(BASEDIR)
  

# test object files
$(OUTDIR)\test\function\dynamic\list_suite.obj: $(OUTDIR) $(TESTDIR)\function\dynamic\list_suite.c
  $(cc) $(WOODPILECFLAGS) \
        /Fo$(OUTDIR)\test\function\dynamic\ \
        /Fd$(OUTDIR)\test\function\dynamic\list_suite.pdb \
        $(TESTDIR)\function\dynamic\list_suite.c \
        /DTEST_FUNCTION_BUILD=BuildDList \
        /DTEST_FUNCTION_COPY=DListCopy \
        /DTEST_FUNCTION_DESTROY=DListDestroy \
        /DTEST_FUNCTION_IS_EMPTY=DListIsEmpty \
        /DTEST_FUNCTION_NEW=DListNew \
        /DTEST_FUNCTION_SIZE=DListSize \
        /DTEST_TYPE=dlist_t

$(OUTDIR)\test\function\dynamic\list_common.obj: $(OUTDIR) $(TESTDIR)\function\common_suite.c
  $(cc) $(WOODPILECFLAGS) \
        /Fo$(OUTDIR)\test\function\dynamic\list_common.obj \
        /Fd$(OUTDIR)\test\function\dynamic\list_common.pdb \
        $(TESTDIR)\function\common_suite.c \
        /DTEST_FUNCTION_BUILD=BuildDList \
        /DTEST_FUNCTION_COPY=DListCopy \
        /DTEST_FUNCTION_DESTROY=DListDestroy \
        /DTEST_FUNCTION_IS_EMPTY=DListIsEmpty \
        /DTEST_FUNCTION_NEW=DListNew \
        /DTEST_FUNCTION_SIZE=DListSize \
        /DTEST_TYPE=dlist_t
  
$(OUTDIR)\test\function\dynamic\list\const_iterator_suite.obj: $(OUTDIR) $(TESTDIR)\function\dynamic\list\const_iterator_suite.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\test\function\dynamic\list\ /Fd$(OUTDIR)\test\function\dynamic\list\const_iterator.pdb $(TESTDIR)\function\dynamic\list\const_iterator_suite.c
  
$(OUTDIR)\test\function\dynamic\list\iterator_suite.obj: $(OUTDIR) $(TESTDIR)\function\dynamic\list\iterator_suite.c
  $(cc) $(WOODPILECFLAGS) \
        /Fo$(OUTDIR)\test\function\dynamic\list\ \
        /Fd$(OUTDIR)\test\function\dynamic\list\iterator.pdb \
        $(TESTDIR)\function\dynamic\list\iterator_suite.c \
        /DTEST_FUNCTION_COPY=DListItrCopy \
        /DTEST_FUNCTION_DESTROY=DListItrDestroy \
        /DTEST_TYPE=dlist_itr_t
  
$(OUTDIR)\test\function\dynamic\list\iterator_common.obj: $(OUTDIR) $(TESTDIR)\function\common_suite.c
  $(cc) $(WOODPILECFLAGS) \
        /Fo$(OUTDIR)\test\function\dynamic\list\iterator_common.obj \
        /Fd$(OUTDIR)\test\function\dynamic\list\iterator_common.pdb \
        $(TESTDIR)\function\common_suite.c \
        /DTEST_FUNCTION_COPY=DListItrCopy \
        /DTEST_FUNCTION_DESTROY=DListItrDestroy \
        /DTEST_TYPE=dlist_itr_t
  
$(OUTDIR)\test\function\dynamic\tree\splay_suite.obj: $(OUTDIR) $(TESTDIR)\function\dynamic\tree\splay_suite.c
  $(cc) $(WOODPILECFLAGS) \
        /Fo$(OUTDIR)\test\function\dynamic\tree\ \
        /Fd$(OUTDIR)\test\function\dynamic\tree\splay.pdb \
        $(TESTDIR)\function\dynamic\tree\splay_suite.c \
        /DTEST_FUNCTION_BUILD=BuildDSplay \
        /DTEST_FUNCTION_COPY=DSplayCopy \
        /DTEST_FUNCTION_DESTROY=DSplayDestroy \
        /DTEST_FUNCTION_IS_EMPTY=DSplayIsEmpty \
        /DTEST_FUNCTION_NEW=DSplayNew \
        /DTEST_FUNCTION_SIZE=DSplaySize \
        /DTEST_TYPE=dsplay_t

$(OUTDIR)\test\function\dynamic\tree\splay_common.obj: $(OUTDIR) $(TESTDIR)\function\common_suite.c
  $(cc) $(WOODPILECFLAGS) \
        /Fo$(OUTDIR)\test\function\dynamic\tree\splay_common.obj \
        /Fd$(OUTDIR)\test\function\dynamic\tree\splay_common.pdb \
        $(TESTDIR)\function\common_suite.c \
        /DTEST_FUNCTION_BUILD=BuildDSplay \
        /DTEST_FUNCTION_COPY=DSplayCopy \
        /DTEST_FUNCTION_DESTROY=DSplayDestroy \
        /DTEST_FUNCTION_IS_EMPTY=DSplayIsEmpty \
        /DTEST_FUNCTION_NEW=DSplayNew \
        /DTEST_FUNCTION_SIZE=DSplaySize \
        /DTEST_TYPE=dsplay_t
  
$(OUTDIR)\test\function\dynamic\tree\splay\const_iterator_suite.obj: $(OUTDIR) $(TESTDIR)\function\dynamic\tree\splay\const_iterator_suite.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\test\function\dynamic\tree\splay\ /Fd$(OUTDIR)\test\function\dynamic\tree\splay\const_iterator.pdb $(TESTDIR)\function\dynamic\tree\splay\const_iterator_suite.c
  
$(OUTDIR)\test\function\dynamic\tree\splay\iterator_suite.obj: $(OUTDIR) $(TESTDIR)\function\dynamic\tree\splay\iterator_suite.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\test\function\dynamic\tree\splay\ /Fd$(OUTDIR)\test\function\dynamic\tree\splay\iterator.pdb $(TESTDIR)\function\dynamic\tree\splay\iterator_suite.c
  
$(OUTDIR)\test\function\static\hash_suite.obj: $(OUTDIR) $(TESTDIR)\function\static\hash_suite.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\test\function\static\ \
        /Fd$(OUTDIR)\test\function\static\hash_suite.pdb \
        $(TESTDIR)\function\static\hash_suite.c \
        /DTEST_FUNCTION_BUILD=BuildSHash \
        /DTEST_FUNCTION_COPY=SHashCopy \
        /DTEST_FUNCTION_DESTROY=SHashDestroy \
        /DTEST_FUNCTION_IS_EMPTY=SHashIsEmpty \
        /DTEST_FUNCTION_NEW=SHashNew \
        /DTEST_FUNCTION_SIZE=SHashSize \
        /DTEST_TYPE=shash_t

$(OUTDIR)\test\function\static\hash_common.obj: $(OUTDIR) $(TESTDIR)\function\common_suite.c
  $(cc) $(WOODPILECFLAGS) \
        /Fo$(OUTDIR)\test\function\static\hash_common.obj \
        /Fd$(OUTDIR)\test\function\static\hash_common.pdb \
        $(TESTDIR)\function\common_suite.c \
        /DTEST_FUNCTION_BUILD=BuildSHash \
        /DTEST_FUNCTION_COPY=SHashCopy \
        /DTEST_FUNCTION_DESTROY=SHashDestroy \
        /DTEST_FUNCTION_IS_EMPTY=SHashIsEmpty \
        /DTEST_FUNCTION_NEW=SHashNew \
        /DTEST_FUNCTION_SIZE=SHashSize \
        /DTEST_TYPE=shash_t
  
$(OUTDIR)\test\function\static\queue_suite.obj: $(OUTDIR) $(TESTDIR)\function\static\queue_suite.c
  $(cc) $(WOODPILECFLAGS) \
        /Fo$(OUTDIR)\test\function\static\ \
        /Fd$(OUTDIR)\test\function\static\queue_suite.pdb \
        $(TESTDIR)\function\static\queue_suite.c \
        /DTEST_FUNCTION_BUILD=BuildSQueue \
        /DTEST_FUNCTION_COPY=SQueueCopy \
        /DTEST_FUNCTION_DESTROY=SQueueDestroy \
        /DTEST_FUNCTION_IS_EMPTY=SQueueIsEmpty \
        /DTEST_FUNCTION_NEW=SQueueNew \
        /DTEST_FUNCTION_SIZE=SQueueSize \
        /DTEST_TYPE=squeue_t

$(OUTDIR)\test\function\static\queue_common.obj: $(OUTDIR) $(TESTDIR)\function\common_suite.c
  $(cc) $(WOODPILECFLAGS) \
        /Fo$(OUTDIR)\test\function\static\queue_common.obj \
        /Fd$(OUTDIR)\test\function\static\queue_common.pdb \
        $(TESTDIR)\function\common_suite.c \
        /DTEST_FUNCTION_BUILD=BuildSQueue \
        /DTEST_FUNCTION_COPY=SQueueCopy \
        /DTEST_FUNCTION_DESTROY=SQueueDestroy \
        /DTEST_FUNCTION_IS_EMPTY=SQueueIsEmpty \
        /DTEST_FUNCTION_NEW=SQueueNew \
        /DTEST_FUNCTION_SIZE=SQueueSize \
        /DTEST_TYPE=squeue_t
  
$(OUTDIR)\test\function\static\stack_suite.obj: $(OUTDIR) $(TESTDIR)\function\static\stack_suite.c
  $(cc) $(WOODPILECFLAGS) /Fo$(OUTDIR)\test\function\static\ /Fd$(OUTDIR)\test\function\static\stack_suite.pdb $(TESTDIR)\function\static\stack_suite.c
  
clean:
  $(CLEANUP)
