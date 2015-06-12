<?php
/**
 * @file
 * ssu_auth_ldap.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ssu_auth_ldap_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ldap_authentication_conf';
  $strongarm->value = array(
    'sids' => array(
      'ldaps' => 'ldaps',
    ),
    'authenticationMode' => 1,
    'loginUIUsernameTxt' => 'Seawolf Username',
    'loginUIPasswordTxt' => NULL,
    'ldapUserHelpLinkUrl' => 'https://ldaps.sonoma.edu/password/',
    'ldapUserHelpLinkText' => 'Logon Help',
    'emailOption' => 3,
    'emailUpdate' => 1,
    'passwordOption' => 2,
    'allowOnlyIfTextInDn' => array(),
    'excludeIfTextInDn' => array(),
    'allowTestPhp' => '',
    'excludeIfNoAuthorizations' => NULL,
    'ssoRemoteUserStripDomainName' => NULL,
    'ssoExcludedPaths' => array(),
    'ssoExcludedHosts' => array(),
    'seamlessLogin' => NULL,
    'ssoNotifyAuthentication' => NULL,
    'ldapImplementation' => NULL,
    'cookieExpire' => NULL,
    'emailTemplate' => '@username@fake-domain.com',
    'emailTemplateHandling' => 1,
    'templateUsagePromptUser' => 0,
    'templateUsageNeverUpdate' => 0,
    'templateUsageResolveConflict' => 0,
    'templateUsagePromptRegex' => '.*@fake-domain\\.com',
    'templateUsageRedirectOnLogin' => 0,
  );
  $export['ldap_authentication_conf'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ldap_servers_encryption';
  $strongarm->value = 10;
  $export['ldap_servers_encryption'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ldap_servers_require_ssl_for_credentails';
  $strongarm->value = 1;
  $export['ldap_servers_require_ssl_for_credentails'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ldap_user_conf';
  $strongarm->value = array(
    'drupalAcctProvisionServer' => 'ldaps',
    'ldapEntryProvisionServer' => 0,
    'drupalAcctProvisionTriggers' => array(
      2 => '2',
      1 => '1',
    ),
    'ldapEntryProvisionTriggers' => array(
      6 => '6',
      7 => '7',
      8 => '8',
      3 => 0,
    ),
    'orphanedDrupalAcctBehavior' => 'user_cancel_block',
    'orphanedCheckQty' => '100',
    'userConflictResolve' => 2,
    'manualAccountConflict' => '2',
    'acctCreation' => 1,
    'ldapUserSynchMappings' => array(
      1 => array(
        '[field.field_name]' => array(
          'ldap_attr' => '[cn]',
          'user_attr' => '[field.field_name]',
          'convert' => 0,
          'direction' => '1',
          'user_tokens' => NULL,
          'config_module' => 'ldap_user',
          'prov_module' => 'ldap_user',
          'enabled' => 1,
          'prov_events' => array(
            0 => 2,
            1 => 1,
          ),
        ),
      ),
    ),
    'disableAdminPasswordField' => 1,
  );
  $export['ldap_user_conf'] = $strongarm;

  return $export;
}
