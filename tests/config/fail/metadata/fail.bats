#!/usr/bin/env bats

load ../../../common
load ../../common

@test 'unknown property in metadata object makes barectf fail' {
  barectf_assert_file_exists unknown-prop.yaml
  barectf_config_check_fail
}

@test 'wrong "env" property type in metadata object makes barectf fail' {
  barectf_assert_file_exists env-invalid-type.yaml
  barectf_config_check_fail
}

@test 'invalid "env" key (invalid C identifier) in metadata object makes barectf fail' {
  barectf_assert_file_exists env-key-invalid-identifier.yaml
  barectf_config_check_fail
}

@test 'invalid "env" value (not an int/string) in metadata object makes barectf fail' {
  barectf_assert_file_exists env-value-invalid-type.yaml
  barectf_config_check_fail
}

@test 'wrong "clocks" property type in metadata object makes barectf fail' {
  barectf_assert_file_exists clocks-invalid-type.yaml
  barectf_config_check_fail
}

@test 'invalid "clocks" key (invalid C identifier) in metadata object makes barectf fail' {
  barectf_assert_file_exists clocks-key-invalid-identifier.yaml
  barectf_config_check_fail
}

@test 'wrong "$log-levels" property type in metadata object makes barectf fail' {
  barectf_assert_file_exists ll-invalid-type.yaml
  barectf_config_check_fail
}

@test 'wrong "$log-levels" property value type in metadata object makes barectf fail' {
  barectf_assert_file_exists ll-value-invalid-type.yaml
  barectf_config_check_fail
}

@test 'wrong "type-aliases" property type in metadata object makes barectf fail' {
  barectf_assert_file_exists ta-invalid-type.yaml
  barectf_config_check_fail
}

@test 'no "trace" property in metadata object makes barectf fail' {
  barectf_assert_file_exists trace-no.yaml
  barectf_config_check_fail
}

@test 'wrong "trace" property type in metadata object makes barectf fail' {
  barectf_assert_file_exists trace-invalid-type.yaml
  barectf_config_check_fail
}

@test 'empty "trace" property in metadata object makes barectf fail' {
  barectf_assert_file_exists trace-empty.yaml
  barectf_config_check_fail
}

@test 'no "streams" property in metadata object makes barectf fail' {
  barectf_assert_file_exists streams-no.yaml
  barectf_config_check_fail
}

@test 'wrong "streams" property type in metadata object makes barectf fail' {
  barectf_assert_file_exists streams-invalid-type.yaml
  barectf_config_check_fail
}

@test 'empty "streams" property in metadata object makes barectf fail' {
  barectf_assert_file_exists streams-empty.yaml
  barectf_config_check_fail
}

@test 'invalid "streams" key (invalid C identifier) in metadata object makes barectf fail' {
  barectf_assert_file_exists streams-key-invalid-identifier.yaml
  barectf_config_check_fail
}
