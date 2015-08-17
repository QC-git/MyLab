@echo off
start ../../../dep/libs/protoc_d.exe --proto_path=. test_person.proto --cpp_out=.
pause