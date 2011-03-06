<?php

/**
 * Form builder for states example.
 * @see http://api.drupal.org/api/drupal/developer--topics--forms_api_reference.html/7#states.
 * @see http://api.drupal.org/api/drupal/includes--common.inc/function/drupal_process_states/7.
 */
function form_fun_blam_form($form, &$form_state) {
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
  );

  // Demonstrate the use of the new #states FAPI property. When a user clicks
  // the status checkbox display an additional textfield.
  $form['status'] = array(
    '#type' => 'checkbox',
    '#title' => t('I have a partner in crime'),
  );
  $form['partner'] = array(
    '#type' => 'textfield',
    '#title' => t('Partner\'s name'),
    '#states' => array(
      'visible' => array(
        ':input[name="status"]' => array('checked' => TRUE),
      ),
    ),
  );

  return $form;
}