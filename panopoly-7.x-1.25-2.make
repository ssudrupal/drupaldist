; This file was auto-generated by drush make
core = 7.x
api = 2

; Core
projects[drupal][version] = "7.38"

; Modules
; Please fill the following out. Type may be one of get, git, bzr or svn,
; and url is the url of the download.
projects[panopoly][download][type] = ""
projects[panopoly][download][url] = ""
projects[panopoly][type] = "module"
projects[panopoly][version] = "1.25"

projects[views_bulk_operations][version] = "3.3"

projects[admin_views][version] = "1.5"

projects[apps][version] = "1.0-rc1"

projects[backports][version] = "1.0-alpha1"

projects[backup_migrate][version] = "3.1"

projects[breakpoints][version] = "1.3"
projects[breakpoints][patches][0] = "https://www.drupal.org/files/issues/2415363-breakpoints-menu_rebuild-13.patch"

projects[ctools][version] = "1.7"
projects[ctools][patches][0] = "http://www.drupal.org/files/issues/ctools-keyboard-trap-2280853-37.patch"

projects[caption_filter][version] = "1.2+9-dev"
projects[caption_filter][patches][0] = "https://www.drupal.org/files/issues/caption_filter-single-quotes-to-entities.patch"

projects[facetapi][version] = "1.5"

projects[date][version] = "2.9-rc1"

projects[date_popup_authored][version] = "1.1+2-dev"

projects[defaultconfig][version] = "1.0-alpha9"
projects[defaultconfig][patches][0] = "http://drupal.org/files/default_config_delete_only_if_overriden.patch"
projects[defaultconfig][patches][1] = "http://drupal.org/files/defaultconfig_include_features_file.patch"
projects[defaultconfig][patches][2] = "http://drupal.org/files/defaultconfig-rebuild-filters-2008178-4_0.patch"
projects[defaultconfig][patches][3] = "http://drupal.org/files/fix-defaultconfig_rebuild_all.patch"
projects[defaultconfig][patches][4] = "http://drupal.org/files/1900574.defaultconfig.undefinedindex_11.patch"

projects[devel][version] = "1.5"

projects[distro_update][version] = "1.0-beta4"

projects[entity][version] = "1.6"

projects[entityreference][version] = "1.1"

projects[fape][version] = "1.2"

projects[features][version] = "2.6"

projects[feeds][version] = "2.0-beta1"

projects[feeds_tamper][version] = "1.1"

projects[field_group][version] = "1.4"

projects[fieldable_panels_panes][version] = "1.6"

projects[file_entity][version] = "2.0-beta1"

projects[geofield][version] = "2.3"

projects[geophp][version] = "1.7"

projects[panels][version] = "3.5"
projects[panels][patches][0] = "https://www.drupal.org/files/issues/panels-export-indentation-2448825-1.patch"
projects[panels][patches][1] = "https://www.drupal.org/files/issues/panels-focus-add-content-tab-2390803-13.patch"

projects[image_resize_filter][version] = "1.14"

projects[job_scheduler][version] = "2.0-alpha3"

projects[jquery_update][version] = "2.6"

projects[leaflet][version] = "1.1"

projects[leaflet_more_maps][version] = "1.13"

projects[libraries][version] = "2.2"

projects[link][version] = "1.3"

projects[linkit][version] = "3.3"
projects[linkit][patches][0] = "http://drupal.org/files/issues/linkit-2115763-18-text-format-switching.patch"

projects[manualcrop][version] = "1.5+4-dev"

projects[masquerade][version] = "1.0-rc7"

projects[media][version] = "2.0-alpha4"
projects[media][patches][0] = "https://www.drupal.org/files/issues/media_wysiwyg_2126697-53.patch"
projects[media][patches][1] = "https://www.drupal.org/files/issues/media-alt-title-double-encoded-2308487-2.patch"
projects[media][patches][2] = "http://www.drupal.org/files/issues/media-file-name-focus-2084287-2.patch"
projects[media][patches][3] = "https://www.drupal.org/files/issues/media-library-preview-overflow-2421589-3.patch"

projects[media_vimeo][version] = "2.0"
projects[media_vimeo][patches][0] = "https://www.drupal.org/files/issues/no_exception_handling-2446199-1.patch"

projects[media_youtube][version] = "3.0"

projects[menu_block][version] = "2.7"

projects[migrate][version] = "2.8"

projects[module_filter][version] = "2.0"

projects[navbar][version] = "1.0-alpha10+8-dev"
projects[navbar][patches][0] = "http://drupal.org/files/navbar-conflict-1757466-14.patch"
projects[navbar][patches][1] = "http://drupal.org/files/z-index-heart-cools-2050559-1.patch"

projects[og][version] = "2.7"

projects[panelizer][version] = "3.1"
projects[panelizer][patches][0] = "http://drupal.org/files/issues/array-to-object-on-update-1623536-26.patch"
projects[panelizer][patches][1] = "http://www.drupal.org/files/issues/panelizer-search_api-2416505-3.patch"

projects[panels_breadcrumbs][version] = "2.2"

projects[panopoly_admin][version] = "1.25"

projects[panopoly_core][version] = "1.25"

projects[panopoly_images][version] = "1.25"

projects[panopoly_magic][version] = "1.25"

projects[panopoly_pages][version] = "1.25"

projects[panopoly_search][version] = "1.25"

projects[panopoly_theme][version] = "1.25"

projects[panopoly_users][version] = "1.25"

projects[panopoly_widgets][version] = "1.25"

projects[panopoly_wysiwyg][version] = "1.25"

projects[pathauto][version] = "1.2"
projects[pathauto][patches][0] = "http://drupal.org/files/issues/pathauto-persist-936222-195-pathauto-state.patch"

projects[pm_existing_pages][version] = "1.4"

projects[radix_layouts][version] = "3.4"

projects[room_reservations][version] = "2.x-dev"

projects[save_draft][version] = "1.4"

projects[search_api][version] = "1.14"

projects[search_api_db][version] = "1.4"
projects[search_api_db][patches][0] = "https://www.drupal.org/files/issues/entity-type-indhold-doest-specify-a-type-for-the-nid-property-2428693-2.patch"
projects[search_api_db][patches][1] = "https://www.drupal.org/files/issues/2436341-search_api_db-updb-1.patch"
projects[search_api_db][patches][2] = "https://www.drupal.org/files/issues/2343371-search_api_db-update-table-8.patch"

projects[search_api_solr][version] = "1.6"

projects[simple_gmap][version] = "1.2"

projects[simplified_menu_admin][version] = "1.0-beta2"

projects[strongarm][version] = "2.0"

projects[tablefield][version] = "2.3"

projects[tipsy][version] = "1.0-rc1"

projects[token][version] = "1.6"

projects[transliteration][version] = "3.2"

projects[user_picture_field][version] = "1.0-rc1"

projects[uuid][version] = "1.0-alpha6"

projects[views][version] = "3.11"
projects[views][patches][0] = "http://drupal.org/files/views-exposed-sorts-2037469-1.patch"
projects[views][patches][1] = "http://drupal.org/files/issues/views-ajax-nginx-1036962-71.patch"
projects[views][patches][2] = "http://drupal.org/files/views-exposed-sorts-2037469-1.patch"
projects[views][patches][3] = "http://drupal.org/files/issues/views-ajax-nginx-1036962-71.patch"

projects[views_autocomplete_filters][version] = "1.1"
projects[views_autocomplete_filters][patches][0] = "http://drupal.org/files/issues/ViewsAutocompleteFilters-no_results_on_some_environments-2277453-1.patch"
projects[views_autocomplete_filters][patches][1] = "http://www.drupal.org/files/issues/views_autocomplete_filters-cache-2374709-2.patch"
projects[views_autocomplete_filters][patches][2] = "http://www.drupal.org/files/issues/views_autocomplete_filters-content-pane-2317351-4.patch"

projects[webform][version] = "4.10"

projects[wysiwyg][version] = "2.2"
projects[wysiwyg][patches][0] = "http://drupal.org/files/wysiwyg-table-format.patch"
projects[wysiwyg][patches][1] = "http://drupal.org/files/wysiwyg-arbitrary_image_paths_markitup-1786732-3.patch"
projects[wysiwyg][patches][2] = "http://drupal.org/files/wysiwyg-1802394-4.patch"
projects[wysiwyg][patches][3] = "https://drupal.org/files/wysiwyg-one-format.934976.23-alt.patch"
projects[wysiwyg][patches][4] = "https://www.drupal.org/files/issues/wysiwyg-1757684.28.patch"

projects[wysiwyg_filter][version] = "1.6-rc2"

; Themes
projects[responsive_bartik][version] = "1.0"

; Libraries
; Please fill the following out. Type may be one of get, git, bzr or svn,
; and url is the url of the download.
libraries[jquery.imagesloaded][download][type] = ""
libraries[jquery.imagesloaded][download][url] = ""
libraries[jquery.imagesloaded][directory_name] = "jquery.imagesloaded"
libraries[jquery.imagesloaded][type] = "library"

; Please fill the following out. Type may be one of get, git, bzr or svn,
; and url is the url of the download.
libraries[markitup][download][type] = ""
libraries[markitup][download][url] = ""
libraries[markitup][directory_name] = "markitup"
libraries[markitup][type] = "library"

; Please fill the following out. Type may be one of get, git, bzr or svn,
; and url is the url of the download.
libraries[respondjs][download][type] = ""
libraries[respondjs][download][url] = ""
libraries[respondjs][directory_name] = "respondjs"
libraries[respondjs][type] = "library"

; Please fill the following out. Type may be one of get, git, bzr or svn,
; and url is the url of the download.
libraries[jquery.imgareaselect][download][type] = ""
libraries[jquery.imgareaselect][download][url] = ""
libraries[jquery.imgareaselect][directory_name] = "jquery.imgareaselect"
libraries[jquery.imgareaselect][type] = "library"

; Please fill the following out. Type may be one of get, git, bzr or svn,
; and url is the url of the download.
libraries[underscore][download][type] = ""
libraries[underscore][download][url] = ""
libraries[underscore][directory_name] = "underscore"
libraries[underscore][type] = "library"

; Please fill the following out. Type may be one of get, git, bzr or svn,
; and url is the url of the download.
libraries[backbone][download][type] = ""
libraries[backbone][download][url] = ""
libraries[backbone][directory_name] = "backbone"
libraries[backbone][type] = "library"

; Please fill the following out. Type may be one of get, git, bzr or svn,
; and url is the url of the download.
libraries[tinymce][download][type] = ""
libraries[tinymce][download][url] = ""
libraries[tinymce][directory_name] = "tinymce"
libraries[tinymce][type] = "library"

; Please fill the following out. Type may be one of get, git, bzr or svn,
; and url is the url of the download.
libraries[SolrPhpClient][download][type] = ""
libraries[SolrPhpClient][download][url] = ""
libraries[SolrPhpClient][directory_name] = "SolrPhpClient"
libraries[SolrPhpClient][type] = "library"

; Please fill the following out. Type may be one of get, git, bzr or svn,
; and url is the url of the download.
libraries[leaflet][download][type] = ""
libraries[leaflet][download][url] = ""
libraries[leaflet][directory_name] = "leaflet"
libraries[leaflet][type] = "library"

