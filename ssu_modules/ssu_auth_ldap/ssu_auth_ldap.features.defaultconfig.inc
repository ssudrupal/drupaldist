<?php
/**
 * @file
 * ssu_auth_ldap.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function ssu_auth_ldap_defaultconfig_features() {
  return array(
    'ssu_auth_ldap' => array(
      'strongarm' => 'strongarm',
    ),
  );
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function ssu_auth_ldap_defaultconfig_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_active_group_delete_filtered';
  $strongarm->value = 0;
  $export['simple_ldap_active_group_delete_filtered'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_active_group_group';
  $strongarm->value = 'cn=g_admin,ou=posixGroups,o=sonoma,o=edu';
  $export['simple_ldap_active_group_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_basedn';
  $strongarm->value = 'ou=people,o=sonoma,o=edu';
  $export['simple_ldap_basedn'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_binddn';
  $strongarm->value = 'uid=drupal_auth,ou=people,o=sonoma,o=edu';
  $export['simple_ldap_binddn'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_bindpw';
  $strongarm->value = 'DrierEwmor';
  $export['simple_ldap_bindpw'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_debug';
  $strongarm->value = 0;
  $export['simple_ldap_debug'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_host';
  $strongarm->value = 'ldaps://ldaps.sonoma.edu';
  $export['simple_ldap_host'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_opt_referrals';
  $strongarm->value = 1;
  $export['simple_ldap_opt_referrals'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_pagesize';
  $strongarm->value = '';
  $export['simple_ldap_pagesize'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_port';
  $strongarm->value = '636';
  $export['simple_ldap_port'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_readonly';
  $strongarm->value = 1;
  $export['simple_ldap_readonly'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_role_attribute_member';
  $strongarm->value = 'member';
  $export['simple_ldap_role_attribute_member'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_role_attribute_member_default';
  $strongarm->value = '';
  $export['simple_ldap_role_attribute_member_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_role_attribute_member_format';
  $strongarm->value = 'dn';
  $export['simple_ldap_role_attribute_member_format'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_role_attribute_name';
  $strongarm->value = 'cn';
  $export['simple_ldap_role_attribute_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_role_basedn';
  $strongarm->value = 'ou=Groups,o=sonoma,o=edu';
  $export['simple_ldap_role_basedn'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_role_filter';
  $strongarm->value = 'cn=drupal_*';
  $export['simple_ldap_role_filter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_role_objectclass';
  $strongarm->value = array(
    'groupofnames' => 'groupofnames',
  );
  $export['simple_ldap_role_objectclass'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_role_scope';
  $strongarm->value = 'one';
  $export['simple_ldap_role_scope'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_role_source';
  $strongarm->value = 'ldap';
  $export['simple_ldap_role_source'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_role_sync';
  $strongarm->value = 'hook_user_load';
  $export['simple_ldap_role_sync'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_starttls';
  $strongarm->value = 1;
  $export['simple_ldap_starttls'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_user_attribute_mail';
  $strongarm->value = 'mail';
  $export['simple_ldap_user_attribute_mail'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_user_attribute_name';
  $strongarm->value = 'uid';
  $export['simple_ldap_user_attribute_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_user_attribute_pass';
  $strongarm->value = 'userpassword';
  $export['simple_ldap_user_attribute_pass'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_user_basedn';
  $strongarm->value = 'ou=people,o=sonoma,o=edu';
  $export['simple_ldap_user_basedn'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_user_filter';
  $strongarm->value = '';
  $export['simple_ldap_user_filter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_user_objectclass';
  $strongarm->value = array(
    'inetorgperson' => 'inetorgperson',
  );
  $export['simple_ldap_user_objectclass'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_user_password_hash';
  $strongarm->value = 'salted sha';
  $export['simple_ldap_user_password_hash'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_user_scope';
  $strongarm->value = 'sub';
  $export['simple_ldap_user_scope'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_user_source';
  $strongarm->value = 'ldap';
  $export['simple_ldap_user_source'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simple_ldap_user_sync';
  $strongarm->value = 'hook_user_load';
  $export['simple_ldap_user_sync'] = $strongarm;

  return $export;
}
