#!/bin/bash
function testGetOpts1()
{
  local TMP_OPTIND=$OPTIND
  OPTIND=1
  echo -e "\n+ testGetOpts1() $@"
  while getopts  "a:b:c:d:" flag
  do
    echo "$flag" IND=$OPTIND ARG=$OPTARG
  done
  echo  OPTIND=$OPTIND
  echo ""
  OPTIND=$TMP_OPTIND
}

function testGetOpts2()
{
  local TMP_OPTIND=$OPTIND
  OPTIND=1
  echo -e "\n+ testGetOpts2() $@"
  while getopts  "a:b:c:" flag
  do
    echo "$flag" IND=$OPTIND ARG=$OPTARG
  done
  echo  OPTIND=$OPTIND
  echo ""
  OPTIND=$TMP_OPTIND
}

function testGetOpts3()
{
  local TMP_OPTIND=$OPTIND
  OPTIND=1
  echo -e "\n+ testGetOpts3() $@"
  while getopts  "abc:def:ghi" flag
  do
    echo "$flag" IND=$OPTIND ARG=$OPTARG
  done

  OPTIND=$TMP_OPTIND
}

testGetOpts2 -a "A" -b "B" -c "C"
testGetOpts2 -a "A" -b "B"
testGetOpts2 -a "A"
testGetOpts1 -a "A" -b "B" -c "C" -d "D"
testGetOpts3 -a -bc foo -f "foo bar" -h -gde
