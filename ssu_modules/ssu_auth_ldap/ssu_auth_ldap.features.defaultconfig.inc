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
      'default_ldap_authorization' => 'default_ldap_authorization',
      'default_ldap_servers' => 'default_ldap_servers',
      'field_default_fields' => 'field_default_fields',
      'strongarm' => 'strongarm',
    ),
  );
}

/**
 * Implements hook_defaultconfig_default_ldap_authorization().
 */
function ssu_auth_ldap_defaultconfig_default_ldap_authorization() {
  $export = array();

  $consumer_type = new stdClass();
  $consumer_type->disabled = FALSE; /* Edit this to true to make a default consumer_type disabled initially */
  $consumer_type->api_version = 1;
  $consumer_type->sid = 'ldaps';
  $consumer_type->consumer_type = 'drupal_role';
  $consumer_type->consumer_module = 'ldap_authorization_drupal_role';
  $consumer_type->status = TRUE;
  $consumer_type->only_ldap_authenticated = TRUE;
  $consumer_type->use_first_attr_as_groupid = FALSE;
  $consumer_type->mappings = 'a:1:{i:0;a:6:{s:12:"user_entered";s:13:"administrator";s:4:"from";s:40:"cn=g_admin,ou=posixGroups,o=sonoma,o=edu";s:10:"normalized";s:13:"administrator";s:10:"simplified";s:13:"administrator";s:5:"valid";b:0;s:13:"error_message";s:101:"Role <em class="placeholder">administrator</em>_name does not exist and role creation is not enabled.";}}';
  $consumer_type->use_filter = TRUE;
  $consumer_type->synch_to_ldap = FALSE;
  $consumer_type->synch_on_logon = TRUE;
  $consumer_type->revoke_ldap_provisioned = TRUE;
  $consumer_type->create_consumers = FALSE;
  $consumer_type->regrant_ldap_provisioned = TRUE;
  $export['drupal_role'] = $consumer_type;

  return $export;
}

/**
 * Implements hook_defaultconfig_default_ldap_servers().
 */
function ssu_auth_ldap_defaultconfig_default_ldap_servers() {
  $export = array();

  $ldap_servers_conf = new stdClass();
  $ldap_servers_conf->disabled = FALSE; /* Edit this to true to make a default ldap_servers_conf disabled initially */
  $ldap_servers_conf->api_version = 1;
  $ldap_servers_conf->sid = 'ldaps';
  $ldap_servers_conf->name = 'SSU LDAP';
  $ldap_servers_conf->status = TRUE;
  $ldap_servers_conf->ldap_type = 'openldap';
  $ldap_servers_conf->address = 'ldaps.sonoma.edu';
  $ldap_servers_conf->port = 389;
  $ldap_servers_conf->tls = TRUE;
  $ldap_servers_conf->followrefs = FALSE;
  $ldap_servers_conf->bind_method = 1;
  $ldap_servers_conf->binddn = 'uid=drupal_auth,ou=people,o=sonoma,o=edu';
  $ldap_servers_conf->bindpw = 'DrierEwmor';
  $ldap_servers_conf->basedn = array(
    0 => 'ou=people,o=sonoma,o=edu',
    1 => 'ou=posixGroups,o=sonoma,o=edu',
    2 => 'ou=Groups,o=sonoma,o=edu',
  );
  $ldap_servers_conf->user_attr = 'uid';
  $ldap_servers_conf->account_name_attr = '';
  $ldap_servers_conf->mail_attr = 'mail';
  $ldap_servers_conf->mail_template = '';
  $ldap_servers_conf->picture_attr = '';
  $ldap_servers_conf->unique_persistent_attr = 'dn';
  $ldap_servers_conf->unique_persistent_attr_binary = FALSE;
  $ldap_servers_conf->user_dn_expression = '';
  $ldap_servers_conf->ldap_to_drupal_user = '';
  $ldap_servers_conf->testing_drupal_username = '';
  $ldap_servers_conf->testing_drupal_user_dn = '';
  $ldap_servers_conf->grp_unused = FALSE;
  $ldap_servers_conf->grp_object_cat = 'posixgroup';
  $ldap_servers_conf->grp_nested = FALSE;
  $ldap_servers_conf->grp_user_memb_attr_exists = FALSE;
  $ldap_servers_conf->grp_user_memb_attr = '';
  $ldap_servers_conf->grp_memb_attr = 'memberuid';
  $ldap_servers_conf->grp_memb_attr_match_user_attr = 'uid';
  $ldap_servers_conf->grp_derive_from_dn = FALSE;
  $ldap_servers_conf->grp_derive_from_dn_attr = '';
  $ldap_servers_conf->grp_test_grp_dn = '';
  $ldap_servers_conf->grp_test_grp_dn_writeable = '';
  $ldap_servers_conf->search_pagination = FALSE;
  $ldap_servers_conf->search_page_size = 100;
  $ldap_servers_conf->weight = 0;
  $export['ldaps'] = $ldap_servers_conf;

  return $export;
}

/**
 * Implements hook_defaultconfig_field_default_fields().
 */
function ssu_auth_ldap_defaultconfig_field_default_fields() {
  $fields = array();

  // Exported field: 'user-user-ldap_user_current_dn'.
  $fields['user-user-ldap_user_current_dn'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(
        0 => 'user',
      ),
      'field_name' => 'ldap_user_current_dn',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 1,
      'module' => 'text',
      'no_ui' => 1,
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => 0,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'user',
      'default_value' => NULL,
      'default_value_function' => 'ldap_user_dn_default',
      'deleted' => 0,
      'description' => 'May change when user\'s DN changes. This field should not be edited.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 7,
        ),
        'featured' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 3,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 3,
        ),
      ),
      'entity_type' => 'user',
      'field_name' => 'ldap_user_current_dn',
      'label' => 'User LDAP DN',
      'required' => 0,
      'settings' => array(
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'ldap_user',
        'settings' => array(),
        'type' => 'ldap_user_hidden',
        'weight' => 11,
      ),
    ),
  );

  // Exported field: 'user-user-ldap_user_last_checked'.
  $fields['user-user-ldap_user_last_checked'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(
        0 => 'user',
      ),
      'field_name' => 'ldap_user_last_checked',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => 1,
      'module' => 'number',
      'no_ui' => 1,
      'settings' => array(),
      'translatable' => 0,
      'type' => 'number_integer',
    ),
    'field_instance' => array(
      'bundle' => 'user',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => 'This field should not be edited.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 9,
        ),
        'featured' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 5,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 5,
        ),
      ),
      'entity_type' => 'user',
      'field_name' => 'ldap_user_last_checked',
      'label' => 'Unix timestamp of when Drupal user was compard to ldap entry.  This could be for purposes of synching, deleteing drupal account, etc.',
      'required' => 0,
      'settings' => array(
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'ldap_user',
        'settings' => array(),
        'type' => 'ldap_user_hidden',
        'weight' => 13,
      ),
    ),
  );

  // Exported field: 'user-user-ldap_user_ldap_exclude'.
  $fields['user-user-ldap_user_ldap_exclude'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(
        0 => 'user',
      ),
      'field_name' => 'ldap_user_ldap_exclude',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => 1,
      'module' => 'number',
      'no_ui' => 1,
      'settings' => array(),
      'translatable' => 0,
      'type' => 'number_integer',
    ),
    'field_instance' => array(
      'bundle' => 'user',
      'default_value' => 0,
      'deleted' => 0,
      'description' => 'This field should not be edited.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 10,
        ),
        'featured' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 6,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 6,
        ),
      ),
      'entity_type' => 'user',
      'field_name' => 'ldap_user_ldap_exclude',
      'label' => 'Whether to exclude the user from LDAP functionality',
      'required' => 0,
      'settings' => array(
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'ldap_user',
        'settings' => array(),
        'type' => 'ldap_user_hidden',
        'weight' => 14,
      ),
    ),
  );

  // Exported field: 'user-user-ldap_user_prov_entries'.
  $fields['user-user-ldap_user_prov_entries'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => -1,
      'deleted' => 0,
      'entity_types' => array(
        0 => 'user',
      ),
      'field_name' => 'ldap_user_prov_entries',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 1,
      'module' => 'text',
      'no_ui' => 1,
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => 0,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'user',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => 'This field should not be edited.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 8,
        ),
        'featured' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 4,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 4,
        ),
      ),
      'entity_type' => 'user',
      'field_name' => 'ldap_user_prov_entries',
      'label' => 'LDAP Entries that have been provisioned from this Drupal user.',
      'required' => 0,
      'settings' => array(
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'ldap_user',
        'settings' => array(),
        'type' => 'ldap_user_hidden',
        'weight' => 12,
      ),
    ),
  );

  // Exported field: 'user-user-ldap_user_puid'.
  $fields['user-user-ldap_user_puid'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(
        0 => 'user',
      ),
      'field_name' => 'ldap_user_puid',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 1,
      'module' => 'text',
      'no_ui' => 1,
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => 0,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'user',
      'default_value' => NULL,
      'default_value_function' => 'ldap_user_puid_default',
      'deleted' => 0,
      'description' => 'This field should not be edited.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 5,
        ),
        'featured' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 1,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 1,
        ),
      ),
      'entity_type' => 'user',
      'field_name' => 'ldap_user_puid',
      'label' => 'Value of user\'s permanent unique id.  This should never change for a given ldap identified user.',
      'required' => 0,
      'settings' => array(
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'ldap_user',
        'settings' => array(),
        'type' => 'ldap_user_hidden',
        'weight' => 9,
      ),
    ),
  );

  // Exported field: 'user-user-ldap_user_puid_property'.
  $fields['user-user-ldap_user_puid_property'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(
        0 => 'user',
      ),
      'field_name' => 'ldap_user_puid_property',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 1,
      'module' => 'text',
      'no_ui' => 1,
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => 0,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'user',
      'default_value' => NULL,
      'default_value_function' => 'ldap_user_puid_property_default',
      'deleted' => 0,
      'description' => 'This field should not be edited.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 6,
        ),
        'featured' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 2,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 2,
        ),
      ),
      'entity_type' => 'user',
      'field_name' => 'ldap_user_puid_property',
      'label' => 'Property specified as user\'s puid.',
      'required' => 0,
      'settings' => array(
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'ldap_user',
        'settings' => array(),
        'type' => 'ldap_user_hidden',
        'weight' => 10,
      ),
    ),
  );

  // Exported field: 'user-user-ldap_user_puid_sid'.
  $fields['user-user-ldap_user_puid_sid'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(
        0 => 'user',
      ),
      'field_name' => 'ldap_user_puid_sid',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 1,
      'module' => 'text',
      'no_ui' => 1,
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => 0,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'user',
      'default_value' => NULL,
      'default_value_function' => 'ldap_user_provisioned_sid_default',
      'deleted' => 0,
      'description' => 'This field should not be edited.',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 4,
        ),
        'featured' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'user',
      'field_name' => 'ldap_user_puid_sid',
      'label' => 'LDAP Server ID that puid was derived from.  NULL if puid is independent of server configuration instance.',
      'required' => 0,
      'settings' => array(
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'ldap_user',
        'settings' => array(),
        'type' => 'ldap_user_hidden',
        'weight' => 8,
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('LDAP Entries that have been provisioned from this Drupal user.');
  t('LDAP Server ID that puid was derived from.  NULL if puid is independent of server configuration instance.');
  t('May change when user\'s DN changes. This field should not be edited.');
  t('Property specified as user\'s puid.');
  t('This field should not be edited.');
  t('Unix timestamp of when Drupal user was compard to ldap entry.  This could be for purposes of synching, deleteing drupal account, etc.');
  t('User LDAP DN');
  t('Value of user\'s permanent unique id.  This should never change for a given ldap identified user.');
  t('Whether to exclude the user from LDAP functionality');

  return $fields;
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function ssu_auth_ldap_defaultconfig_strongarm() {
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
