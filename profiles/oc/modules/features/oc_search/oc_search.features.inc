<?php
/**
 * @file
 * oc_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oc_search_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function oc_search_default_search_api_index() {
  $items = array();
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Default node index",
    "machine_name" : "default_node_index",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : "database",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "1",
            "bundles" : { "featured_content" : "featured_content" }
          }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_project_goal" : true,
              "body:value" : true,
              "field_project_supervisor:name" : true,
              "field_project_supervisor:mail" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_desctitle" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_email" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_first_name" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_lab" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_last_name" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_telephone" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_title" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_project_goal" : true,
              "body:value" : true,
              "field_project_supervisor:name" : true,
              "field_project_supervisor:mail" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_desctitle" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_email" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_first_name" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_lab" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_last_name" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_telephone" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_title" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_project_goal" : true,
              "body:value" : true,
              "field_project_supervisor:name" : true,
              "field_project_supervisor:mail" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_desctitle" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_email" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_first_name" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_lab" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_last_name" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_telephone" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_title" : true
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_project_goal" : true,
              "body:value" : true,
              "field_project_supervisor:name" : true,
              "field_project_supervisor:mail" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_desctitle" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_email" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_first_name" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_lab" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_last_name" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_telephone" : true,
              "field_project_supervisor:profile_researcher_profile:field_rprofile_title" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      },
      "fields" : {
        "type" : { "type" : "string" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "created" : { "type" : "date" },
        "changed" : { "type" : "date" },
        "comment_count" : { "type" : "integer" },
        "field_project_goal" : { "type" : "text" },
        "field_project_host" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_project_nrpositions" : { "type" : "integer" },
        "field_project_status" : { "type" : "string" },
        "field_project_supervisor" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "user" },
        "field_article_date" : { "type" : "date" },
        "field_article_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_event_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "search_api_language" : { "type" : "string" },
        "body:value" : { "type" : "text" },
        "body:summary" : { "type" : "text" },
        "field_partner_address:country" : { "type" : "string" },
        "field_partner_address:locality" : { "type" : "text" },
        "partner_profiles:field_rprofile_desctitle" : { "type" : "list\\u003Ctext\\u003E" },
        "partner_profiles:field_rprofile_email" : { "type" : "list\\u003Ctext\\u003E" },
        "partner_profiles:field_rprofile_first_name" : { "type" : "list\\u003Ctext\\u003E" },
        "partner_profiles:field_rprofile_lab" : { "type" : "list\\u003Ctext\\u003E" },
        "partner_profiles:field_rprofile_last_name" : { "type" : "list\\u003Ctext\\u003E" },
        "partner_profiles:field_rprofile_partner_ref" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "partner_profiles:field_rprofile_telephone" : { "type" : "list\\u003Ctext\\u003E" },
        "partner_profiles:field_rprofile_title" : { "type" : "list\\u003Ctext\\u003E" },
        "field_project_supervisor:profile_researcher_profile:field_rprofile_desctitle" : { "type" : "list\\u003Ctext\\u003E" },
        "field_project_supervisor:profile_researcher_profile:field_rprofile_email" : { "type" : "list\\u003Ctext\\u003E" },
        "field_project_supervisor:profile_researcher_profile:field_rprofile_first_name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_project_supervisor:profile_researcher_profile:field_rprofile_lab" : { "type" : "list\\u003Ctext\\u003E" },
        "field_project_supervisor:profile_researcher_profile:field_rprofile_last_name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_project_supervisor:profile_researcher_profile:field_rprofile_partner_ref" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_project_supervisor:profile_researcher_profile:field_rprofile_telephone" : { "type" : "list\\u003Ctext\\u003E" },
        "field_project_supervisor:profile_researcher_profile:field_rprofile_title" : { "type" : "list\\u003Ctext\\u003E" }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_page().
 */
function oc_search_default_search_api_page() {
  $items = array();
  $items['oc_search'] = entity_import('search_api_page', '{
    "index_id" : "default_node_index",
    "path" : "search",
    "name" : "Search",
    "machine_name" : "oc_search",
    "description" : "",
    "options" : {
      "mode" : "terms",
      "fields" : [],
      "per_page" : "10",
      "get_per_page" : 1,
      "view_mode" : "search"
    },
    "enabled" : "1"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function oc_search_default_search_api_server() {
  $items = array();
  $items['database'] = entity_import('search_api_server', '{
    "name" : "Database",
    "machine_name" : "database",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "3",
      "indexes" : {
        "default_node_index" : {
          "type" : {
            "table" : "search_api_db_default_node_index_type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_default_node_index_title",
            "type" : "text",
            "boost" : "5.0"
          },
          "created" : {
            "table" : "search_api_db_default_node_index_created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_default_node_index_changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "comment_count" : {
            "table" : "search_api_db_default_node_index_comment_count",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_default_node_index_search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_default_node_index_body_value",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_project_goal" : {
            "table" : "search_api_db_default_node_index_field_project_goal",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_project_host" : {
            "table" : "search_api_db_default_node_index_field_project_host",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_project_supervisor" : {
            "table" : "search_api_db_default_node_index_field_project_supervisor",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_article_tags" : {
            "table" : "search_api_db_default_node_index_field_article_tags",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_event_tags" : {
            "table" : "search_api_db_default_node_index_field_event_tags",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_article_date" : {
            "table" : "search_api_db_default_node_index_field_article_date",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_project_nrpositions" : {
            "table" : "search_api_db_default_node_index_field_project_nrpositions",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_project_status" : {
            "table" : "search_api_db_default_node_index_field_project_status",
            "type" : "string",
            "boost" : "1.0"
          },
          "body:summary" : {
            "table" : "search_api_db_default_node_index_body_summary",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_partner_address:country" : {
            "table" : "search_api_db_default_node_index_field_partner_address_country",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_partner_address:locality" : {
            "table" : "search_api_db_default_node_index_field_partner_address_locality",
            "type" : "text",
            "boost" : "1.0"
          },
          "partner_profiles:field_rprofile_first_name" : {
            "table" : "search_api_db_default_node_index_partner_profiles_field_rprofil",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "partner_profiles:field_rprofile_desctitle" : {
            "table" : "search_api_db_default_node_index_partner_profiles_field_rprof_1",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "partner_profiles:field_rprofile_email" : {
            "table" : "search_api_db_default_node_index_partner_profiles_field_rprof_2",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "partner_profiles:field_rprofile_lab" : {
            "table" : "search_api_db_default_node_index_partner_profiles_field_rprof_3",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "partner_profiles:field_rprofile_last_name" : {
            "table" : "search_api_db_default_node_index_partner_profiles_field_rprof_4",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "partner_profiles:field_rprofile_partner_ref" : {
            "table" : "search_api_db_default_node_index_partner_profiles_field_rprof_5",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "partner_profiles:field_rprofile_telephone" : {
            "table" : "search_api_db_default_node_index_partner_profiles_field_rprof_6",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "partner_profiles:field_rprofile_title" : {
            "table" : "search_api_db_default_node_index_partner_profiles_field_rprof_7",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_project_supervisor:profile_researcher_profile:field_rprofile_desctitle" : {
            "table" : "search_api_db_default_node_index_field_project_supervisor_profi",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_project_supervisor:profile_researcher_profile:field_rprofile_email" : {
            "table" : "search_api_db_default_node_index_field_project_supervisor_pro_1",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_project_supervisor:profile_researcher_profile:field_rprofile_first_name" : {
            "table" : "search_api_db_default_node_index_field_project_supervisor_pro_2",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_project_supervisor:profile_researcher_profile:field_rprofile_lab" : {
            "table" : "search_api_db_default_node_index_field_project_supervisor_pro_3",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_project_supervisor:profile_researcher_profile:field_rprofile_last_name" : {
            "table" : "search_api_db_default_node_index_field_project_supervisor_pro_4",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_project_supervisor:profile_researcher_profile:field_rprofile_partner_ref" : {
            "table" : "search_api_db_default_node_index_field_project_supervisor_pro_5",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_project_supervisor:profile_researcher_profile:field_rprofile_telephone" : {
            "table" : "search_api_db_default_node_index_field_project_supervisor_pro_6",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_project_supervisor:profile_researcher_profile:field_rprofile_title" : {
            "table" : "search_api_db_default_node_index_field_project_supervisor_pro_7",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          }
        },
        "profiles" : {
          "url" : {
            "table" : "search_api_db_profiles_url",
            "type" : "uri",
            "boost" : "1.0"
          },
          "field_rprofile_desctitle" : {
            "table" : "search_api_db_profiles_field_rprofile_desctitle",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_rprofile_email" : {
            "table" : "search_api_db_profiles_field_rprofile_email",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_rprofile_first_name" : {
            "table" : "search_api_db_profiles_field_rprofile_first_name",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_rprofile_lab" : {
            "table" : "search_api_db_profiles_field_rprofile_lab",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_rprofile_last_name" : {
            "table" : "search_api_db_profiles_field_rprofile_last_name",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_rprofile_partner_ref" : {
            "table" : "search_api_db_profiles_field_rprofile_partner_ref",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_rprofile_telephone" : {
            "table" : "search_api_db_profiles_field_rprofile_telephone",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_rprofile_title" : {
            "table" : "search_api_db_profiles_field_rprofile_title",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_profiles_search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "search_api_url" : {
            "table" : "search_api_db_profiles_search_api_url",
            "type" : "uri",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1"
  }');
  return $items;
}
