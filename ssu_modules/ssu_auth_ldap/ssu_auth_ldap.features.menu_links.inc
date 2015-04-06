<?php
/**
 * @file
 * ssu_auth_ldap.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ssu_auth_ldap_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_ldap-configuration:admin/config/people/ldap
  $menu_links['management_ldap-configuration:admin/config/people/ldap'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/people/ldap',
    'router_path' => 'admin/config/people/ldap',
    'link_title' => 'LDAP Configuration',
    'options' => array(
      'attributes' => array(
        'title' => 'LDAP authentication, authorization, provisioning, etc.',
      ),
      'identifier' => 'management_ldap-configuration:admin/config/people/ldap',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_people:admin/config/people',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('LDAP Configuration');


  return $menu_links;
}
