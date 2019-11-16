#ifndef FONTAWESOME_H
#define FONTAWESOME_H

#include <QObject>
#include <QFontDatabase>
#include <QQmlApplicationEngine>

namespace bpp {

    class FontAwesome : public QObject
    {
        Q_OBJECT
    public:
        explicit FontAwesome(QObject *parent = nullptr);

        Q_PROPERTY(QString regular READ get_regular CONSTANT)
        Q_PROPERTY(QString solid READ get_solid CONSTANT)
        Q_PROPERTY(QString brands READ get_brands CONSTANT)

        const QString& get_regular() const {return regular;}
        const QString& get_solid() const {return solid;}
        const QString& get_brands() const {return brands;}

        bool registerFont(const QString& fontFile);

        static void registerQml(QQmlApplicationEngine& engine);

    protected:
        QString regular;
        QString solid;
        QString brands;

        //Follow setup/readme.md and
        //PASTE fa_class.h CONTENT FROM HERE
    public:
        Q_PROPERTY(QString fa_500px READ get_fa_500px CONSTANT)
        Q_PROPERTY(QString fa_accessible_icon READ get_fa_accessible_icon CONSTANT)
        Q_PROPERTY(QString fa_accusoft READ get_fa_accusoft CONSTANT)
        Q_PROPERTY(QString fa_acquisitions_incorporated READ get_fa_acquisitions_incorporated CONSTANT)
        Q_PROPERTY(QString fa_ad READ get_fa_ad CONSTANT)
        Q_PROPERTY(QString fa_address_book READ get_fa_address_book CONSTANT)
        Q_PROPERTY(QString fa_address_card READ get_fa_address_card CONSTANT)
        Q_PROPERTY(QString fa_adjust READ get_fa_adjust CONSTANT)
        Q_PROPERTY(QString fa_adn READ get_fa_adn CONSTANT)
        Q_PROPERTY(QString fa_adobe READ get_fa_adobe CONSTANT)
        Q_PROPERTY(QString fa_adversal READ get_fa_adversal CONSTANT)
        Q_PROPERTY(QString fa_affiliatetheme READ get_fa_affiliatetheme CONSTANT)
        Q_PROPERTY(QString fa_air_freshener READ get_fa_air_freshener CONSTANT)
        Q_PROPERTY(QString fa_airbnb READ get_fa_airbnb CONSTANT)
        Q_PROPERTY(QString fa_algolia READ get_fa_algolia CONSTANT)
        Q_PROPERTY(QString fa_align_center READ get_fa_align_center CONSTANT)
        Q_PROPERTY(QString fa_align_justify READ get_fa_align_justify CONSTANT)
        Q_PROPERTY(QString fa_align_left READ get_fa_align_left CONSTANT)
        Q_PROPERTY(QString fa_align_right READ get_fa_align_right CONSTANT)
        Q_PROPERTY(QString fa_alipay READ get_fa_alipay CONSTANT)
        Q_PROPERTY(QString fa_allergies READ get_fa_allergies CONSTANT)
        Q_PROPERTY(QString fa_amazon READ get_fa_amazon CONSTANT)
        Q_PROPERTY(QString fa_amazon_pay READ get_fa_amazon_pay CONSTANT)
        Q_PROPERTY(QString fa_ambulance READ get_fa_ambulance CONSTANT)
        Q_PROPERTY(QString fa_american_sign_language_interpreting READ get_fa_american_sign_language_interpreting CONSTANT)
        Q_PROPERTY(QString fa_amilia READ get_fa_amilia CONSTANT)
        Q_PROPERTY(QString fa_anchor READ get_fa_anchor CONSTANT)
        Q_PROPERTY(QString fa_android READ get_fa_android CONSTANT)
        Q_PROPERTY(QString fa_angellist READ get_fa_angellist CONSTANT)
        Q_PROPERTY(QString fa_angle_double_down READ get_fa_angle_double_down CONSTANT)
        Q_PROPERTY(QString fa_angle_double_left READ get_fa_angle_double_left CONSTANT)
        Q_PROPERTY(QString fa_angle_double_right READ get_fa_angle_double_right CONSTANT)
        Q_PROPERTY(QString fa_angle_double_up READ get_fa_angle_double_up CONSTANT)
        Q_PROPERTY(QString fa_angle_down READ get_fa_angle_down CONSTANT)
        Q_PROPERTY(QString fa_angle_left READ get_fa_angle_left CONSTANT)
        Q_PROPERTY(QString fa_angle_right READ get_fa_angle_right CONSTANT)
        Q_PROPERTY(QString fa_angle_up READ get_fa_angle_up CONSTANT)
        Q_PROPERTY(QString fa_angry READ get_fa_angry CONSTANT)
        Q_PROPERTY(QString fa_angrycreative READ get_fa_angrycreative CONSTANT)
        Q_PROPERTY(QString fa_angular READ get_fa_angular CONSTANT)
        Q_PROPERTY(QString fa_ankh READ get_fa_ankh CONSTANT)
        Q_PROPERTY(QString fa_app_store READ get_fa_app_store CONSTANT)
        Q_PROPERTY(QString fa_app_store_ios READ get_fa_app_store_ios CONSTANT)
        Q_PROPERTY(QString fa_apper READ get_fa_apper CONSTANT)
        Q_PROPERTY(QString fa_apple READ get_fa_apple CONSTANT)
        Q_PROPERTY(QString fa_apple_alt READ get_fa_apple_alt CONSTANT)
        Q_PROPERTY(QString fa_apple_pay READ get_fa_apple_pay CONSTANT)
        Q_PROPERTY(QString fa_archive READ get_fa_archive CONSTANT)
        Q_PROPERTY(QString fa_archway READ get_fa_archway CONSTANT)
        Q_PROPERTY(QString fa_arrow_alt_circle_down READ get_fa_arrow_alt_circle_down CONSTANT)
        Q_PROPERTY(QString fa_arrow_alt_circle_left READ get_fa_arrow_alt_circle_left CONSTANT)
        Q_PROPERTY(QString fa_arrow_alt_circle_right READ get_fa_arrow_alt_circle_right CONSTANT)
        Q_PROPERTY(QString fa_arrow_alt_circle_up READ get_fa_arrow_alt_circle_up CONSTANT)
        Q_PROPERTY(QString fa_arrow_circle_down READ get_fa_arrow_circle_down CONSTANT)
        Q_PROPERTY(QString fa_arrow_circle_left READ get_fa_arrow_circle_left CONSTANT)
        Q_PROPERTY(QString fa_arrow_circle_right READ get_fa_arrow_circle_right CONSTANT)
        Q_PROPERTY(QString fa_arrow_circle_up READ get_fa_arrow_circle_up CONSTANT)
        Q_PROPERTY(QString fa_arrow_down READ get_fa_arrow_down CONSTANT)
        Q_PROPERTY(QString fa_arrow_left READ get_fa_arrow_left CONSTANT)
        Q_PROPERTY(QString fa_arrow_right READ get_fa_arrow_right CONSTANT)
        Q_PROPERTY(QString fa_arrow_up READ get_fa_arrow_up CONSTANT)
        Q_PROPERTY(QString fa_arrows_alt READ get_fa_arrows_alt CONSTANT)
        Q_PROPERTY(QString fa_arrows_alt_h READ get_fa_arrows_alt_h CONSTANT)
        Q_PROPERTY(QString fa_arrows_alt_v READ get_fa_arrows_alt_v CONSTANT)
        Q_PROPERTY(QString fa_artstation READ get_fa_artstation CONSTANT)
        Q_PROPERTY(QString fa_assistive_listening_systems READ get_fa_assistive_listening_systems CONSTANT)
        Q_PROPERTY(QString fa_asterisk READ get_fa_asterisk CONSTANT)
        Q_PROPERTY(QString fa_asymmetrik READ get_fa_asymmetrik CONSTANT)
        Q_PROPERTY(QString fa_at READ get_fa_at CONSTANT)
        Q_PROPERTY(QString fa_atlas READ get_fa_atlas CONSTANT)
        Q_PROPERTY(QString fa_atlassian READ get_fa_atlassian CONSTANT)
        Q_PROPERTY(QString fa_atom READ get_fa_atom CONSTANT)
        Q_PROPERTY(QString fa_audible READ get_fa_audible CONSTANT)
        Q_PROPERTY(QString fa_audio_description READ get_fa_audio_description CONSTANT)
        Q_PROPERTY(QString fa_autoprefixer READ get_fa_autoprefixer CONSTANT)
        Q_PROPERTY(QString fa_avianex READ get_fa_avianex CONSTANT)
        Q_PROPERTY(QString fa_aviato READ get_fa_aviato CONSTANT)
        Q_PROPERTY(QString fa_award READ get_fa_award CONSTANT)
        Q_PROPERTY(QString fa_aws READ get_fa_aws CONSTANT)
        Q_PROPERTY(QString fa_baby READ get_fa_baby CONSTANT)
        Q_PROPERTY(QString fa_baby_carriage READ get_fa_baby_carriage CONSTANT)
        Q_PROPERTY(QString fa_backspace READ get_fa_backspace CONSTANT)
        Q_PROPERTY(QString fa_backward READ get_fa_backward CONSTANT)
        Q_PROPERTY(QString fa_bacon READ get_fa_bacon CONSTANT)
        Q_PROPERTY(QString fa_balance_scale READ get_fa_balance_scale CONSTANT)
        Q_PROPERTY(QString fa_balance_scale_left READ get_fa_balance_scale_left CONSTANT)
        Q_PROPERTY(QString fa_balance_scale_right READ get_fa_balance_scale_right CONSTANT)
        Q_PROPERTY(QString fa_ban READ get_fa_ban CONSTANT)
        Q_PROPERTY(QString fa_band_aid READ get_fa_band_aid CONSTANT)
        Q_PROPERTY(QString fa_bandcamp READ get_fa_bandcamp CONSTANT)
        Q_PROPERTY(QString fa_barcode READ get_fa_barcode CONSTANT)
        Q_PROPERTY(QString fa_bars READ get_fa_bars CONSTANT)
        Q_PROPERTY(QString fa_baseball_ball READ get_fa_baseball_ball CONSTANT)
        Q_PROPERTY(QString fa_basketball_ball READ get_fa_basketball_ball CONSTANT)
        Q_PROPERTY(QString fa_bath READ get_fa_bath CONSTANT)
        Q_PROPERTY(QString fa_battery_empty READ get_fa_battery_empty CONSTANT)
        Q_PROPERTY(QString fa_battery_full READ get_fa_battery_full CONSTANT)
        Q_PROPERTY(QString fa_battery_half READ get_fa_battery_half CONSTANT)
        Q_PROPERTY(QString fa_battery_quarter READ get_fa_battery_quarter CONSTANT)
        Q_PROPERTY(QString fa_battery_three_quarters READ get_fa_battery_three_quarters CONSTANT)
        Q_PROPERTY(QString fa_battle_net READ get_fa_battle_net CONSTANT)
        Q_PROPERTY(QString fa_bed READ get_fa_bed CONSTANT)
        Q_PROPERTY(QString fa_beer READ get_fa_beer CONSTANT)
        Q_PROPERTY(QString fa_behance READ get_fa_behance CONSTANT)
        Q_PROPERTY(QString fa_behance_square READ get_fa_behance_square CONSTANT)
        Q_PROPERTY(QString fa_bell READ get_fa_bell CONSTANT)
        Q_PROPERTY(QString fa_bell_slash READ get_fa_bell_slash CONSTANT)
        Q_PROPERTY(QString fa_bezier_curve READ get_fa_bezier_curve CONSTANT)
        Q_PROPERTY(QString fa_bible READ get_fa_bible CONSTANT)
        Q_PROPERTY(QString fa_bicycle READ get_fa_bicycle CONSTANT)
        Q_PROPERTY(QString fa_biking READ get_fa_biking CONSTANT)
        Q_PROPERTY(QString fa_bimobject READ get_fa_bimobject CONSTANT)
        Q_PROPERTY(QString fa_binoculars READ get_fa_binoculars CONSTANT)
        Q_PROPERTY(QString fa_biohazard READ get_fa_biohazard CONSTANT)
        Q_PROPERTY(QString fa_birthday_cake READ get_fa_birthday_cake CONSTANT)
        Q_PROPERTY(QString fa_bitbucket READ get_fa_bitbucket CONSTANT)
        Q_PROPERTY(QString fa_bitcoin READ get_fa_bitcoin CONSTANT)
        Q_PROPERTY(QString fa_bity READ get_fa_bity CONSTANT)
        Q_PROPERTY(QString fa_black_tie READ get_fa_black_tie CONSTANT)
        Q_PROPERTY(QString fa_blackberry READ get_fa_blackberry CONSTANT)
        Q_PROPERTY(QString fa_blender READ get_fa_blender CONSTANT)
        Q_PROPERTY(QString fa_blender_phone READ get_fa_blender_phone CONSTANT)
        Q_PROPERTY(QString fa_blind READ get_fa_blind CONSTANT)
        Q_PROPERTY(QString fa_blog READ get_fa_blog CONSTANT)
        Q_PROPERTY(QString fa_blogger READ get_fa_blogger CONSTANT)
        Q_PROPERTY(QString fa_blogger_b READ get_fa_blogger_b CONSTANT)
        Q_PROPERTY(QString fa_bluetooth READ get_fa_bluetooth CONSTANT)
        Q_PROPERTY(QString fa_bluetooth_b READ get_fa_bluetooth_b CONSTANT)
        Q_PROPERTY(QString fa_bold READ get_fa_bold CONSTANT)
        Q_PROPERTY(QString fa_bolt READ get_fa_bolt CONSTANT)
        Q_PROPERTY(QString fa_bomb READ get_fa_bomb CONSTANT)
        Q_PROPERTY(QString fa_bone READ get_fa_bone CONSTANT)
        Q_PROPERTY(QString fa_bong READ get_fa_bong CONSTANT)
        Q_PROPERTY(QString fa_book READ get_fa_book CONSTANT)
        Q_PROPERTY(QString fa_book_dead READ get_fa_book_dead CONSTANT)
        Q_PROPERTY(QString fa_book_medical READ get_fa_book_medical CONSTANT)
        Q_PROPERTY(QString fa_book_open READ get_fa_book_open CONSTANT)
        Q_PROPERTY(QString fa_book_reader READ get_fa_book_reader CONSTANT)
        Q_PROPERTY(QString fa_bookmark READ get_fa_bookmark CONSTANT)
        Q_PROPERTY(QString fa_bootstrap READ get_fa_bootstrap CONSTANT)
        Q_PROPERTY(QString fa_border_all READ get_fa_border_all CONSTANT)
        Q_PROPERTY(QString fa_border_none READ get_fa_border_none CONSTANT)
        Q_PROPERTY(QString fa_border_style READ get_fa_border_style CONSTANT)
        Q_PROPERTY(QString fa_bowling_ball READ get_fa_bowling_ball CONSTANT)
        Q_PROPERTY(QString fa_box READ get_fa_box CONSTANT)
        Q_PROPERTY(QString fa_box_open READ get_fa_box_open CONSTANT)
        Q_PROPERTY(QString fa_boxes READ get_fa_boxes CONSTANT)
        Q_PROPERTY(QString fa_braille READ get_fa_braille CONSTANT)
        Q_PROPERTY(QString fa_brain READ get_fa_brain CONSTANT)
        Q_PROPERTY(QString fa_bread_slice READ get_fa_bread_slice CONSTANT)
        Q_PROPERTY(QString fa_briefcase READ get_fa_briefcase CONSTANT)
        Q_PROPERTY(QString fa_briefcase_medical READ get_fa_briefcase_medical CONSTANT)
        Q_PROPERTY(QString fa_broadcast_tower READ get_fa_broadcast_tower CONSTANT)
        Q_PROPERTY(QString fa_broom READ get_fa_broom CONSTANT)
        Q_PROPERTY(QString fa_brush READ get_fa_brush CONSTANT)
        Q_PROPERTY(QString fa_btc READ get_fa_btc CONSTANT)
        Q_PROPERTY(QString fa_buffer READ get_fa_buffer CONSTANT)
        Q_PROPERTY(QString fa_bug READ get_fa_bug CONSTANT)
        Q_PROPERTY(QString fa_building READ get_fa_building CONSTANT)
        Q_PROPERTY(QString fa_bullhorn READ get_fa_bullhorn CONSTANT)
        Q_PROPERTY(QString fa_bullseye READ get_fa_bullseye CONSTANT)
        Q_PROPERTY(QString fa_burn READ get_fa_burn CONSTANT)
        Q_PROPERTY(QString fa_buromobelexperte READ get_fa_buromobelexperte CONSTANT)
        Q_PROPERTY(QString fa_bus READ get_fa_bus CONSTANT)
        Q_PROPERTY(QString fa_bus_alt READ get_fa_bus_alt CONSTANT)
        Q_PROPERTY(QString fa_business_time READ get_fa_business_time CONSTANT)
        Q_PROPERTY(QString fa_buy_n_large READ get_fa_buy_n_large CONSTANT)
        Q_PROPERTY(QString fa_buysellads READ get_fa_buysellads CONSTANT)
        Q_PROPERTY(QString fa_calculator READ get_fa_calculator CONSTANT)
        Q_PROPERTY(QString fa_calendar READ get_fa_calendar CONSTANT)
        Q_PROPERTY(QString fa_calendar_alt READ get_fa_calendar_alt CONSTANT)
        Q_PROPERTY(QString fa_calendar_check READ get_fa_calendar_check CONSTANT)
        Q_PROPERTY(QString fa_calendar_day READ get_fa_calendar_day CONSTANT)
        Q_PROPERTY(QString fa_calendar_minus READ get_fa_calendar_minus CONSTANT)
        Q_PROPERTY(QString fa_calendar_plus READ get_fa_calendar_plus CONSTANT)
        Q_PROPERTY(QString fa_calendar_times READ get_fa_calendar_times CONSTANT)
        Q_PROPERTY(QString fa_calendar_week READ get_fa_calendar_week CONSTANT)
        Q_PROPERTY(QString fa_camera READ get_fa_camera CONSTANT)
        Q_PROPERTY(QString fa_camera_retro READ get_fa_camera_retro CONSTANT)
        Q_PROPERTY(QString fa_campground READ get_fa_campground CONSTANT)
        Q_PROPERTY(QString fa_canadian_maple_leaf READ get_fa_canadian_maple_leaf CONSTANT)
        Q_PROPERTY(QString fa_candy_cane READ get_fa_candy_cane CONSTANT)
        Q_PROPERTY(QString fa_cannabis READ get_fa_cannabis CONSTANT)
        Q_PROPERTY(QString fa_capsules READ get_fa_capsules CONSTANT)
        Q_PROPERTY(QString fa_car READ get_fa_car CONSTANT)
        Q_PROPERTY(QString fa_car_alt READ get_fa_car_alt CONSTANT)
        Q_PROPERTY(QString fa_car_battery READ get_fa_car_battery CONSTANT)
        Q_PROPERTY(QString fa_car_crash READ get_fa_car_crash CONSTANT)
        Q_PROPERTY(QString fa_car_side READ get_fa_car_side CONSTANT)
        Q_PROPERTY(QString fa_caret_down READ get_fa_caret_down CONSTANT)
        Q_PROPERTY(QString fa_caret_left READ get_fa_caret_left CONSTANT)
        Q_PROPERTY(QString fa_caret_right READ get_fa_caret_right CONSTANT)
        Q_PROPERTY(QString fa_caret_square_down READ get_fa_caret_square_down CONSTANT)
        Q_PROPERTY(QString fa_caret_square_left READ get_fa_caret_square_left CONSTANT)
        Q_PROPERTY(QString fa_caret_square_right READ get_fa_caret_square_right CONSTANT)
        Q_PROPERTY(QString fa_caret_square_up READ get_fa_caret_square_up CONSTANT)
        Q_PROPERTY(QString fa_caret_up READ get_fa_caret_up CONSTANT)
        Q_PROPERTY(QString fa_carrot READ get_fa_carrot CONSTANT)
        Q_PROPERTY(QString fa_cart_arrow_down READ get_fa_cart_arrow_down CONSTANT)
        Q_PROPERTY(QString fa_cart_plus READ get_fa_cart_plus CONSTANT)
        Q_PROPERTY(QString fa_cash_register READ get_fa_cash_register CONSTANT)
        Q_PROPERTY(QString fa_cat READ get_fa_cat CONSTANT)
        Q_PROPERTY(QString fa_cc_amazon_pay READ get_fa_cc_amazon_pay CONSTANT)
        Q_PROPERTY(QString fa_cc_amex READ get_fa_cc_amex CONSTANT)
        Q_PROPERTY(QString fa_cc_apple_pay READ get_fa_cc_apple_pay CONSTANT)
        Q_PROPERTY(QString fa_cc_diners_club READ get_fa_cc_diners_club CONSTANT)
        Q_PROPERTY(QString fa_cc_discover READ get_fa_cc_discover CONSTANT)
        Q_PROPERTY(QString fa_cc_jcb READ get_fa_cc_jcb CONSTANT)
        Q_PROPERTY(QString fa_cc_mastercard READ get_fa_cc_mastercard CONSTANT)
        Q_PROPERTY(QString fa_cc_paypal READ get_fa_cc_paypal CONSTANT)
        Q_PROPERTY(QString fa_cc_stripe READ get_fa_cc_stripe CONSTANT)
        Q_PROPERTY(QString fa_cc_visa READ get_fa_cc_visa CONSTANT)
        Q_PROPERTY(QString fa_centercode READ get_fa_centercode CONSTANT)
        Q_PROPERTY(QString fa_centos READ get_fa_centos CONSTANT)
        Q_PROPERTY(QString fa_certificate READ get_fa_certificate CONSTANT)
        Q_PROPERTY(QString fa_chair READ get_fa_chair CONSTANT)
        Q_PROPERTY(QString fa_chalkboard READ get_fa_chalkboard CONSTANT)
        Q_PROPERTY(QString fa_chalkboard_teacher READ get_fa_chalkboard_teacher CONSTANT)
        Q_PROPERTY(QString fa_charging_station READ get_fa_charging_station CONSTANT)
        Q_PROPERTY(QString fa_chart_area READ get_fa_chart_area CONSTANT)
        Q_PROPERTY(QString fa_chart_bar READ get_fa_chart_bar CONSTANT)
        Q_PROPERTY(QString fa_chart_line READ get_fa_chart_line CONSTANT)
        Q_PROPERTY(QString fa_chart_pie READ get_fa_chart_pie CONSTANT)
        Q_PROPERTY(QString fa_check READ get_fa_check CONSTANT)
        Q_PROPERTY(QString fa_check_circle READ get_fa_check_circle CONSTANT)
        Q_PROPERTY(QString fa_check_double READ get_fa_check_double CONSTANT)
        Q_PROPERTY(QString fa_check_square READ get_fa_check_square CONSTANT)
        Q_PROPERTY(QString fa_cheese READ get_fa_cheese CONSTANT)
        Q_PROPERTY(QString fa_chess READ get_fa_chess CONSTANT)
        Q_PROPERTY(QString fa_chess_bishop READ get_fa_chess_bishop CONSTANT)
        Q_PROPERTY(QString fa_chess_board READ get_fa_chess_board CONSTANT)
        Q_PROPERTY(QString fa_chess_king READ get_fa_chess_king CONSTANT)
        Q_PROPERTY(QString fa_chess_knight READ get_fa_chess_knight CONSTANT)
        Q_PROPERTY(QString fa_chess_pawn READ get_fa_chess_pawn CONSTANT)
        Q_PROPERTY(QString fa_chess_queen READ get_fa_chess_queen CONSTANT)
        Q_PROPERTY(QString fa_chess_rook READ get_fa_chess_rook CONSTANT)
        Q_PROPERTY(QString fa_chevron_circle_down READ get_fa_chevron_circle_down CONSTANT)
        Q_PROPERTY(QString fa_chevron_circle_left READ get_fa_chevron_circle_left CONSTANT)
        Q_PROPERTY(QString fa_chevron_circle_right READ get_fa_chevron_circle_right CONSTANT)
        Q_PROPERTY(QString fa_chevron_circle_up READ get_fa_chevron_circle_up CONSTANT)
        Q_PROPERTY(QString fa_chevron_down READ get_fa_chevron_down CONSTANT)
        Q_PROPERTY(QString fa_chevron_left READ get_fa_chevron_left CONSTANT)
        Q_PROPERTY(QString fa_chevron_right READ get_fa_chevron_right CONSTANT)
        Q_PROPERTY(QString fa_chevron_up READ get_fa_chevron_up CONSTANT)
        Q_PROPERTY(QString fa_child READ get_fa_child CONSTANT)
        Q_PROPERTY(QString fa_chrome READ get_fa_chrome CONSTANT)
        Q_PROPERTY(QString fa_chromecast READ get_fa_chromecast CONSTANT)
        Q_PROPERTY(QString fa_church READ get_fa_church CONSTANT)
        Q_PROPERTY(QString fa_circle READ get_fa_circle CONSTANT)
        Q_PROPERTY(QString fa_circle_notch READ get_fa_circle_notch CONSTANT)
        Q_PROPERTY(QString fa_city READ get_fa_city CONSTANT)
        Q_PROPERTY(QString fa_clinic_medical READ get_fa_clinic_medical CONSTANT)
        Q_PROPERTY(QString fa_clipboard READ get_fa_clipboard CONSTANT)
        Q_PROPERTY(QString fa_clipboard_check READ get_fa_clipboard_check CONSTANT)
        Q_PROPERTY(QString fa_clipboard_list READ get_fa_clipboard_list CONSTANT)
        Q_PROPERTY(QString fa_clock READ get_fa_clock CONSTANT)
        Q_PROPERTY(QString fa_clone READ get_fa_clone CONSTANT)
        Q_PROPERTY(QString fa_closed_captioning READ get_fa_closed_captioning CONSTANT)
        Q_PROPERTY(QString fa_cloud READ get_fa_cloud CONSTANT)
        Q_PROPERTY(QString fa_cloud_download_alt READ get_fa_cloud_download_alt CONSTANT)
        Q_PROPERTY(QString fa_cloud_meatball READ get_fa_cloud_meatball CONSTANT)
        Q_PROPERTY(QString fa_cloud_moon READ get_fa_cloud_moon CONSTANT)
        Q_PROPERTY(QString fa_cloud_moon_rain READ get_fa_cloud_moon_rain CONSTANT)
        Q_PROPERTY(QString fa_cloud_rain READ get_fa_cloud_rain CONSTANT)
        Q_PROPERTY(QString fa_cloud_showers_heavy READ get_fa_cloud_showers_heavy CONSTANT)
        Q_PROPERTY(QString fa_cloud_sun READ get_fa_cloud_sun CONSTANT)
        Q_PROPERTY(QString fa_cloud_sun_rain READ get_fa_cloud_sun_rain CONSTANT)
        Q_PROPERTY(QString fa_cloud_upload_alt READ get_fa_cloud_upload_alt CONSTANT)
        Q_PROPERTY(QString fa_cloudscale READ get_fa_cloudscale CONSTANT)
        Q_PROPERTY(QString fa_cloudsmith READ get_fa_cloudsmith CONSTANT)
        Q_PROPERTY(QString fa_cloudversify READ get_fa_cloudversify CONSTANT)
        Q_PROPERTY(QString fa_cocktail READ get_fa_cocktail CONSTANT)
        Q_PROPERTY(QString fa_code READ get_fa_code CONSTANT)
        Q_PROPERTY(QString fa_code_branch READ get_fa_code_branch CONSTANT)
        Q_PROPERTY(QString fa_codepen READ get_fa_codepen CONSTANT)
        Q_PROPERTY(QString fa_codiepie READ get_fa_codiepie CONSTANT)
        Q_PROPERTY(QString fa_coffee READ get_fa_coffee CONSTANT)
        Q_PROPERTY(QString fa_cog READ get_fa_cog CONSTANT)
        Q_PROPERTY(QString fa_cogs READ get_fa_cogs CONSTANT)
        Q_PROPERTY(QString fa_coins READ get_fa_coins CONSTANT)
        Q_PROPERTY(QString fa_columns READ get_fa_columns CONSTANT)
        Q_PROPERTY(QString fa_comment READ get_fa_comment CONSTANT)
        Q_PROPERTY(QString fa_comment_alt READ get_fa_comment_alt CONSTANT)
        Q_PROPERTY(QString fa_comment_dollar READ get_fa_comment_dollar CONSTANT)
        Q_PROPERTY(QString fa_comment_dots READ get_fa_comment_dots CONSTANT)
        Q_PROPERTY(QString fa_comment_medical READ get_fa_comment_medical CONSTANT)
        Q_PROPERTY(QString fa_comment_slash READ get_fa_comment_slash CONSTANT)
        Q_PROPERTY(QString fa_comments READ get_fa_comments CONSTANT)
        Q_PROPERTY(QString fa_comments_dollar READ get_fa_comments_dollar CONSTANT)
        Q_PROPERTY(QString fa_compact_disc READ get_fa_compact_disc CONSTANT)
        Q_PROPERTY(QString fa_compass READ get_fa_compass CONSTANT)
        Q_PROPERTY(QString fa_compress READ get_fa_compress CONSTANT)
        Q_PROPERTY(QString fa_compress_arrows_alt READ get_fa_compress_arrows_alt CONSTANT)
        Q_PROPERTY(QString fa_concierge_bell READ get_fa_concierge_bell CONSTANT)
        Q_PROPERTY(QString fa_confluence READ get_fa_confluence CONSTANT)
        Q_PROPERTY(QString fa_connectdevelop READ get_fa_connectdevelop CONSTANT)
        Q_PROPERTY(QString fa_contao READ get_fa_contao CONSTANT)
        Q_PROPERTY(QString fa_cookie READ get_fa_cookie CONSTANT)
        Q_PROPERTY(QString fa_cookie_bite READ get_fa_cookie_bite CONSTANT)
        Q_PROPERTY(QString fa_copy READ get_fa_copy CONSTANT)
        Q_PROPERTY(QString fa_copyright READ get_fa_copyright CONSTANT)
        Q_PROPERTY(QString fa_cotton_bureau READ get_fa_cotton_bureau CONSTANT)
        Q_PROPERTY(QString fa_couch READ get_fa_couch CONSTANT)
        Q_PROPERTY(QString fa_cpanel READ get_fa_cpanel CONSTANT)
        Q_PROPERTY(QString fa_creative_commons READ get_fa_creative_commons CONSTANT)
        Q_PROPERTY(QString fa_creative_commons_by READ get_fa_creative_commons_by CONSTANT)
        Q_PROPERTY(QString fa_creative_commons_nc READ get_fa_creative_commons_nc CONSTANT)
        Q_PROPERTY(QString fa_creative_commons_nc_eu READ get_fa_creative_commons_nc_eu CONSTANT)
        Q_PROPERTY(QString fa_creative_commons_nc_jp READ get_fa_creative_commons_nc_jp CONSTANT)
        Q_PROPERTY(QString fa_creative_commons_nd READ get_fa_creative_commons_nd CONSTANT)
        Q_PROPERTY(QString fa_creative_commons_pd READ get_fa_creative_commons_pd CONSTANT)
        Q_PROPERTY(QString fa_creative_commons_pd_alt READ get_fa_creative_commons_pd_alt CONSTANT)
        Q_PROPERTY(QString fa_creative_commons_remix READ get_fa_creative_commons_remix CONSTANT)
        Q_PROPERTY(QString fa_creative_commons_sa READ get_fa_creative_commons_sa CONSTANT)
        Q_PROPERTY(QString fa_creative_commons_sampling READ get_fa_creative_commons_sampling CONSTANT)
        Q_PROPERTY(QString fa_creative_commons_sampling_plus READ get_fa_creative_commons_sampling_plus CONSTANT)
        Q_PROPERTY(QString fa_creative_commons_share READ get_fa_creative_commons_share CONSTANT)
        Q_PROPERTY(QString fa_creative_commons_zero READ get_fa_creative_commons_zero CONSTANT)
        Q_PROPERTY(QString fa_credit_card READ get_fa_credit_card CONSTANT)
        Q_PROPERTY(QString fa_critical_role READ get_fa_critical_role CONSTANT)
        Q_PROPERTY(QString fa_crop READ get_fa_crop CONSTANT)
        Q_PROPERTY(QString fa_crop_alt READ get_fa_crop_alt CONSTANT)
        Q_PROPERTY(QString fa_cross READ get_fa_cross CONSTANT)
        Q_PROPERTY(QString fa_crosshairs READ get_fa_crosshairs CONSTANT)
        Q_PROPERTY(QString fa_crow READ get_fa_crow CONSTANT)
        Q_PROPERTY(QString fa_crown READ get_fa_crown CONSTANT)
        Q_PROPERTY(QString fa_crutch READ get_fa_crutch CONSTANT)
        Q_PROPERTY(QString fa_css3 READ get_fa_css3 CONSTANT)
        Q_PROPERTY(QString fa_css3_alt READ get_fa_css3_alt CONSTANT)
        Q_PROPERTY(QString fa_cube READ get_fa_cube CONSTANT)
        Q_PROPERTY(QString fa_cubes READ get_fa_cubes CONSTANT)
        Q_PROPERTY(QString fa_cut READ get_fa_cut CONSTANT)
        Q_PROPERTY(QString fa_cuttlefish READ get_fa_cuttlefish CONSTANT)
        Q_PROPERTY(QString fa_d_and_d READ get_fa_d_and_d CONSTANT)
        Q_PROPERTY(QString fa_d_and_d_beyond READ get_fa_d_and_d_beyond CONSTANT)
        Q_PROPERTY(QString fa_dashcube READ get_fa_dashcube CONSTANT)
        Q_PROPERTY(QString fa_database READ get_fa_database CONSTANT)
        Q_PROPERTY(QString fa_deaf READ get_fa_deaf CONSTANT)
        Q_PROPERTY(QString fa_delicious READ get_fa_delicious CONSTANT)
        Q_PROPERTY(QString fa_democrat READ get_fa_democrat CONSTANT)
        Q_PROPERTY(QString fa_deploydog READ get_fa_deploydog CONSTANT)
        Q_PROPERTY(QString fa_deskpro READ get_fa_deskpro CONSTANT)
        Q_PROPERTY(QString fa_desktop READ get_fa_desktop CONSTANT)
        Q_PROPERTY(QString fa_dev READ get_fa_dev CONSTANT)
        Q_PROPERTY(QString fa_deviantart READ get_fa_deviantart CONSTANT)
        Q_PROPERTY(QString fa_dharmachakra READ get_fa_dharmachakra CONSTANT)
        Q_PROPERTY(QString fa_dhl READ get_fa_dhl CONSTANT)
        Q_PROPERTY(QString fa_diagnoses READ get_fa_diagnoses CONSTANT)
        Q_PROPERTY(QString fa_diaspora READ get_fa_diaspora CONSTANT)
        Q_PROPERTY(QString fa_dice READ get_fa_dice CONSTANT)
        Q_PROPERTY(QString fa_dice_d20 READ get_fa_dice_d20 CONSTANT)
        Q_PROPERTY(QString fa_dice_d6 READ get_fa_dice_d6 CONSTANT)
        Q_PROPERTY(QString fa_dice_five READ get_fa_dice_five CONSTANT)
        Q_PROPERTY(QString fa_dice_four READ get_fa_dice_four CONSTANT)
        Q_PROPERTY(QString fa_dice_one READ get_fa_dice_one CONSTANT)
        Q_PROPERTY(QString fa_dice_six READ get_fa_dice_six CONSTANT)
        Q_PROPERTY(QString fa_dice_three READ get_fa_dice_three CONSTANT)
        Q_PROPERTY(QString fa_dice_two READ get_fa_dice_two CONSTANT)
        Q_PROPERTY(QString fa_digg READ get_fa_digg CONSTANT)
        Q_PROPERTY(QString fa_digital_ocean READ get_fa_digital_ocean CONSTANT)
        Q_PROPERTY(QString fa_digital_tachograph READ get_fa_digital_tachograph CONSTANT)
        Q_PROPERTY(QString fa_directions READ get_fa_directions CONSTANT)
        Q_PROPERTY(QString fa_discord READ get_fa_discord CONSTANT)
        Q_PROPERTY(QString fa_discourse READ get_fa_discourse CONSTANT)
        Q_PROPERTY(QString fa_divide READ get_fa_divide CONSTANT)
        Q_PROPERTY(QString fa_dizzy READ get_fa_dizzy CONSTANT)
        Q_PROPERTY(QString fa_dna READ get_fa_dna CONSTANT)
        Q_PROPERTY(QString fa_dochub READ get_fa_dochub CONSTANT)
        Q_PROPERTY(QString fa_docker READ get_fa_docker CONSTANT)
        Q_PROPERTY(QString fa_dog READ get_fa_dog CONSTANT)
        Q_PROPERTY(QString fa_dollar_sign READ get_fa_dollar_sign CONSTANT)
        Q_PROPERTY(QString fa_dolly READ get_fa_dolly CONSTANT)
        Q_PROPERTY(QString fa_dolly_flatbed READ get_fa_dolly_flatbed CONSTANT)
        Q_PROPERTY(QString fa_donate READ get_fa_donate CONSTANT)
        Q_PROPERTY(QString fa_door_closed READ get_fa_door_closed CONSTANT)
        Q_PROPERTY(QString fa_door_open READ get_fa_door_open CONSTANT)
        Q_PROPERTY(QString fa_dot_circle READ get_fa_dot_circle CONSTANT)
        Q_PROPERTY(QString fa_dove READ get_fa_dove CONSTANT)
        Q_PROPERTY(QString fa_download READ get_fa_download CONSTANT)
        Q_PROPERTY(QString fa_draft2digital READ get_fa_draft2digital CONSTANT)
        Q_PROPERTY(QString fa_drafting_compass READ get_fa_drafting_compass CONSTANT)
        Q_PROPERTY(QString fa_dragon READ get_fa_dragon CONSTANT)
        Q_PROPERTY(QString fa_draw_polygon READ get_fa_draw_polygon CONSTANT)
        Q_PROPERTY(QString fa_dribbble READ get_fa_dribbble CONSTANT)
        Q_PROPERTY(QString fa_dribbble_square READ get_fa_dribbble_square CONSTANT)
        Q_PROPERTY(QString fa_dropbox READ get_fa_dropbox CONSTANT)
        Q_PROPERTY(QString fa_drum READ get_fa_drum CONSTANT)
        Q_PROPERTY(QString fa_drum_steelpan READ get_fa_drum_steelpan CONSTANT)
        Q_PROPERTY(QString fa_drumstick_bite READ get_fa_drumstick_bite CONSTANT)
        Q_PROPERTY(QString fa_drupal READ get_fa_drupal CONSTANT)
        Q_PROPERTY(QString fa_dumbbell READ get_fa_dumbbell CONSTANT)
        Q_PROPERTY(QString fa_dumpster READ get_fa_dumpster CONSTANT)
        Q_PROPERTY(QString fa_dumpster_fire READ get_fa_dumpster_fire CONSTANT)
        Q_PROPERTY(QString fa_dungeon READ get_fa_dungeon CONSTANT)
        Q_PROPERTY(QString fa_dyalog READ get_fa_dyalog CONSTANT)
        Q_PROPERTY(QString fa_earlybirds READ get_fa_earlybirds CONSTANT)
        Q_PROPERTY(QString fa_ebay READ get_fa_ebay CONSTANT)
        Q_PROPERTY(QString fa_edge READ get_fa_edge CONSTANT)
        Q_PROPERTY(QString fa_edit READ get_fa_edit CONSTANT)
        Q_PROPERTY(QString fa_egg READ get_fa_egg CONSTANT)
        Q_PROPERTY(QString fa_eject READ get_fa_eject CONSTANT)
        Q_PROPERTY(QString fa_elementor READ get_fa_elementor CONSTANT)
        Q_PROPERTY(QString fa_ellipsis_h READ get_fa_ellipsis_h CONSTANT)
        Q_PROPERTY(QString fa_ellipsis_v READ get_fa_ellipsis_v CONSTANT)
        Q_PROPERTY(QString fa_ello READ get_fa_ello CONSTANT)
        Q_PROPERTY(QString fa_ember READ get_fa_ember CONSTANT)
        Q_PROPERTY(QString fa_empire READ get_fa_empire CONSTANT)
        Q_PROPERTY(QString fa_envelope READ get_fa_envelope CONSTANT)
        Q_PROPERTY(QString fa_envelope_open READ get_fa_envelope_open CONSTANT)
        Q_PROPERTY(QString fa_envelope_open_text READ get_fa_envelope_open_text CONSTANT)
        Q_PROPERTY(QString fa_envelope_square READ get_fa_envelope_square CONSTANT)
        Q_PROPERTY(QString fa_envira READ get_fa_envira CONSTANT)
        Q_PROPERTY(QString fa_equals READ get_fa_equals CONSTANT)
        Q_PROPERTY(QString fa_eraser READ get_fa_eraser CONSTANT)
        Q_PROPERTY(QString fa_erlang READ get_fa_erlang CONSTANT)
        Q_PROPERTY(QString fa_ethereum READ get_fa_ethereum CONSTANT)
        Q_PROPERTY(QString fa_ethernet READ get_fa_ethernet CONSTANT)
        Q_PROPERTY(QString fa_etsy READ get_fa_etsy CONSTANT)
        Q_PROPERTY(QString fa_euro_sign READ get_fa_euro_sign CONSTANT)
        Q_PROPERTY(QString fa_evernote READ get_fa_evernote CONSTANT)
        Q_PROPERTY(QString fa_exchange_alt READ get_fa_exchange_alt CONSTANT)
        Q_PROPERTY(QString fa_exclamation READ get_fa_exclamation CONSTANT)
        Q_PROPERTY(QString fa_exclamation_circle READ get_fa_exclamation_circle CONSTANT)
        Q_PROPERTY(QString fa_exclamation_triangle READ get_fa_exclamation_triangle CONSTANT)
        Q_PROPERTY(QString fa_expand READ get_fa_expand CONSTANT)
        Q_PROPERTY(QString fa_expand_arrows_alt READ get_fa_expand_arrows_alt CONSTANT)
        Q_PROPERTY(QString fa_expeditedssl READ get_fa_expeditedssl CONSTANT)
        Q_PROPERTY(QString fa_external_link_alt READ get_fa_external_link_alt CONSTANT)
        Q_PROPERTY(QString fa_external_link_square_alt READ get_fa_external_link_square_alt CONSTANT)
        Q_PROPERTY(QString fa_eye READ get_fa_eye CONSTANT)
        Q_PROPERTY(QString fa_eye_dropper READ get_fa_eye_dropper CONSTANT)
        Q_PROPERTY(QString fa_eye_slash READ get_fa_eye_slash CONSTANT)
        Q_PROPERTY(QString fa_facebook READ get_fa_facebook CONSTANT)
        Q_PROPERTY(QString fa_facebook_f READ get_fa_facebook_f CONSTANT)
        Q_PROPERTY(QString fa_facebook_messenger READ get_fa_facebook_messenger CONSTANT)
        Q_PROPERTY(QString fa_facebook_square READ get_fa_facebook_square CONSTANT)
        Q_PROPERTY(QString fa_fan READ get_fa_fan CONSTANT)
        Q_PROPERTY(QString fa_fantasy_flight_games READ get_fa_fantasy_flight_games CONSTANT)
        Q_PROPERTY(QString fa_fast_backward READ get_fa_fast_backward CONSTANT)
        Q_PROPERTY(QString fa_fast_forward READ get_fa_fast_forward CONSTANT)
        Q_PROPERTY(QString fa_fax READ get_fa_fax CONSTANT)
        Q_PROPERTY(QString fa_feather READ get_fa_feather CONSTANT)
        Q_PROPERTY(QString fa_feather_alt READ get_fa_feather_alt CONSTANT)
        Q_PROPERTY(QString fa_fedex READ get_fa_fedex CONSTANT)
        Q_PROPERTY(QString fa_fedora READ get_fa_fedora CONSTANT)
        Q_PROPERTY(QString fa_female READ get_fa_female CONSTANT)
        Q_PROPERTY(QString fa_fighter_jet READ get_fa_fighter_jet CONSTANT)
        Q_PROPERTY(QString fa_figma READ get_fa_figma CONSTANT)
        Q_PROPERTY(QString fa_file READ get_fa_file CONSTANT)
        Q_PROPERTY(QString fa_file_alt READ get_fa_file_alt CONSTANT)
        Q_PROPERTY(QString fa_file_archive READ get_fa_file_archive CONSTANT)
        Q_PROPERTY(QString fa_file_audio READ get_fa_file_audio CONSTANT)
        Q_PROPERTY(QString fa_file_code READ get_fa_file_code CONSTANT)
        Q_PROPERTY(QString fa_file_contract READ get_fa_file_contract CONSTANT)
        Q_PROPERTY(QString fa_file_csv READ get_fa_file_csv CONSTANT)
        Q_PROPERTY(QString fa_file_download READ get_fa_file_download CONSTANT)
        Q_PROPERTY(QString fa_file_excel READ get_fa_file_excel CONSTANT)
        Q_PROPERTY(QString fa_file_export READ get_fa_file_export CONSTANT)
        Q_PROPERTY(QString fa_file_image READ get_fa_file_image CONSTANT)
        Q_PROPERTY(QString fa_file_import READ get_fa_file_import CONSTANT)
        Q_PROPERTY(QString fa_file_invoice READ get_fa_file_invoice CONSTANT)
        Q_PROPERTY(QString fa_file_invoice_dollar READ get_fa_file_invoice_dollar CONSTANT)
        Q_PROPERTY(QString fa_file_medical READ get_fa_file_medical CONSTANT)
        Q_PROPERTY(QString fa_file_medical_alt READ get_fa_file_medical_alt CONSTANT)
        Q_PROPERTY(QString fa_file_pdf READ get_fa_file_pdf CONSTANT)
        Q_PROPERTY(QString fa_file_powerpoint READ get_fa_file_powerpoint CONSTANT)
        Q_PROPERTY(QString fa_file_prescription READ get_fa_file_prescription CONSTANT)
        Q_PROPERTY(QString fa_file_signature READ get_fa_file_signature CONSTANT)
        Q_PROPERTY(QString fa_file_upload READ get_fa_file_upload CONSTANT)
        Q_PROPERTY(QString fa_file_video READ get_fa_file_video CONSTANT)
        Q_PROPERTY(QString fa_file_word READ get_fa_file_word CONSTANT)
        Q_PROPERTY(QString fa_fill READ get_fa_fill CONSTANT)
        Q_PROPERTY(QString fa_fill_drip READ get_fa_fill_drip CONSTANT)
        Q_PROPERTY(QString fa_film READ get_fa_film CONSTANT)
        Q_PROPERTY(QString fa_filter READ get_fa_filter CONSTANT)
        Q_PROPERTY(QString fa_fingerprint READ get_fa_fingerprint CONSTANT)
        Q_PROPERTY(QString fa_fire READ get_fa_fire CONSTANT)
        Q_PROPERTY(QString fa_fire_alt READ get_fa_fire_alt CONSTANT)
        Q_PROPERTY(QString fa_fire_extinguisher READ get_fa_fire_extinguisher CONSTANT)
        Q_PROPERTY(QString fa_firefox READ get_fa_firefox CONSTANT)
        Q_PROPERTY(QString fa_first_aid READ get_fa_first_aid CONSTANT)
        Q_PROPERTY(QString fa_first_order READ get_fa_first_order CONSTANT)
        Q_PROPERTY(QString fa_first_order_alt READ get_fa_first_order_alt CONSTANT)
        Q_PROPERTY(QString fa_firstdraft READ get_fa_firstdraft CONSTANT)
        Q_PROPERTY(QString fa_fish READ get_fa_fish CONSTANT)
        Q_PROPERTY(QString fa_fist_raised READ get_fa_fist_raised CONSTANT)
        Q_PROPERTY(QString fa_flag READ get_fa_flag CONSTANT)
        Q_PROPERTY(QString fa_flag_checkered READ get_fa_flag_checkered CONSTANT)
        Q_PROPERTY(QString fa_flag_usa READ get_fa_flag_usa CONSTANT)
        Q_PROPERTY(QString fa_flask READ get_fa_flask CONSTANT)
        Q_PROPERTY(QString fa_flickr READ get_fa_flickr CONSTANT)
        Q_PROPERTY(QString fa_flipboard READ get_fa_flipboard CONSTANT)
        Q_PROPERTY(QString fa_flushed READ get_fa_flushed CONSTANT)
        Q_PROPERTY(QString fa_fly READ get_fa_fly CONSTANT)
        Q_PROPERTY(QString fa_folder READ get_fa_folder CONSTANT)
        Q_PROPERTY(QString fa_folder_minus READ get_fa_folder_minus CONSTANT)
        Q_PROPERTY(QString fa_folder_open READ get_fa_folder_open CONSTANT)
        Q_PROPERTY(QString fa_folder_plus READ get_fa_folder_plus CONSTANT)
        Q_PROPERTY(QString fa_font READ get_fa_font CONSTANT)
        Q_PROPERTY(QString fa_font_awesome READ get_fa_font_awesome CONSTANT)
        Q_PROPERTY(QString fa_font_awesome_alt READ get_fa_font_awesome_alt CONSTANT)
        Q_PROPERTY(QString fa_font_awesome_flag READ get_fa_font_awesome_flag CONSTANT)
        Q_PROPERTY(QString fa_font_awesome_logo_full READ get_fa_font_awesome_logo_full CONSTANT)
        Q_PROPERTY(QString fa_fonticons READ get_fa_fonticons CONSTANT)
        Q_PROPERTY(QString fa_fonticons_fi READ get_fa_fonticons_fi CONSTANT)
        Q_PROPERTY(QString fa_football_ball READ get_fa_football_ball CONSTANT)
        Q_PROPERTY(QString fa_fort_awesome READ get_fa_fort_awesome CONSTANT)
        Q_PROPERTY(QString fa_fort_awesome_alt READ get_fa_fort_awesome_alt CONSTANT)
        Q_PROPERTY(QString fa_forumbee READ get_fa_forumbee CONSTANT)
        Q_PROPERTY(QString fa_forward READ get_fa_forward CONSTANT)
        Q_PROPERTY(QString fa_foursquare READ get_fa_foursquare CONSTANT)
        Q_PROPERTY(QString fa_free_code_camp READ get_fa_free_code_camp CONSTANT)
        Q_PROPERTY(QString fa_freebsd READ get_fa_freebsd CONSTANT)
        Q_PROPERTY(QString fa_frog READ get_fa_frog CONSTANT)
        Q_PROPERTY(QString fa_frown READ get_fa_frown CONSTANT)
        Q_PROPERTY(QString fa_frown_open READ get_fa_frown_open CONSTANT)
        Q_PROPERTY(QString fa_fulcrum READ get_fa_fulcrum CONSTANT)
        Q_PROPERTY(QString fa_funnel_dollar READ get_fa_funnel_dollar CONSTANT)
        Q_PROPERTY(QString fa_futbol READ get_fa_futbol CONSTANT)
        Q_PROPERTY(QString fa_galactic_republic READ get_fa_galactic_republic CONSTANT)
        Q_PROPERTY(QString fa_galactic_senate READ get_fa_galactic_senate CONSTANT)
        Q_PROPERTY(QString fa_gamepad READ get_fa_gamepad CONSTANT)
        Q_PROPERTY(QString fa_gas_pump READ get_fa_gas_pump CONSTANT)
        Q_PROPERTY(QString fa_gavel READ get_fa_gavel CONSTANT)
        Q_PROPERTY(QString fa_gem READ get_fa_gem CONSTANT)
        Q_PROPERTY(QString fa_genderless READ get_fa_genderless CONSTANT)
        Q_PROPERTY(QString fa_get_pocket READ get_fa_get_pocket CONSTANT)
        Q_PROPERTY(QString fa_gg READ get_fa_gg CONSTANT)
        Q_PROPERTY(QString fa_gg_circle READ get_fa_gg_circle CONSTANT)
        Q_PROPERTY(QString fa_ghost READ get_fa_ghost CONSTANT)
        Q_PROPERTY(QString fa_gift READ get_fa_gift CONSTANT)
        Q_PROPERTY(QString fa_gifts READ get_fa_gifts CONSTANT)
        Q_PROPERTY(QString fa_git READ get_fa_git CONSTANT)
        Q_PROPERTY(QString fa_git_alt READ get_fa_git_alt CONSTANT)
        Q_PROPERTY(QString fa_git_square READ get_fa_git_square CONSTANT)
        Q_PROPERTY(QString fa_github READ get_fa_github CONSTANT)
        Q_PROPERTY(QString fa_github_alt READ get_fa_github_alt CONSTANT)
        Q_PROPERTY(QString fa_github_square READ get_fa_github_square CONSTANT)
        Q_PROPERTY(QString fa_gitkraken READ get_fa_gitkraken CONSTANT)
        Q_PROPERTY(QString fa_gitlab READ get_fa_gitlab CONSTANT)
        Q_PROPERTY(QString fa_gitter READ get_fa_gitter CONSTANT)
        Q_PROPERTY(QString fa_glass_cheers READ get_fa_glass_cheers CONSTANT)
        Q_PROPERTY(QString fa_glass_martini READ get_fa_glass_martini CONSTANT)
        Q_PROPERTY(QString fa_glass_martini_alt READ get_fa_glass_martini_alt CONSTANT)
        Q_PROPERTY(QString fa_glass_whiskey READ get_fa_glass_whiskey CONSTANT)
        Q_PROPERTY(QString fa_glasses READ get_fa_glasses CONSTANT)
        Q_PROPERTY(QString fa_glide READ get_fa_glide CONSTANT)
        Q_PROPERTY(QString fa_glide_g READ get_fa_glide_g CONSTANT)
        Q_PROPERTY(QString fa_globe READ get_fa_globe CONSTANT)
        Q_PROPERTY(QString fa_globe_africa READ get_fa_globe_africa CONSTANT)
        Q_PROPERTY(QString fa_globe_americas READ get_fa_globe_americas CONSTANT)
        Q_PROPERTY(QString fa_globe_asia READ get_fa_globe_asia CONSTANT)
        Q_PROPERTY(QString fa_globe_europe READ get_fa_globe_europe CONSTANT)
        Q_PROPERTY(QString fa_gofore READ get_fa_gofore CONSTANT)
        Q_PROPERTY(QString fa_golf_ball READ get_fa_golf_ball CONSTANT)
        Q_PROPERTY(QString fa_goodreads READ get_fa_goodreads CONSTANT)
        Q_PROPERTY(QString fa_goodreads_g READ get_fa_goodreads_g CONSTANT)
        Q_PROPERTY(QString fa_google READ get_fa_google CONSTANT)
        Q_PROPERTY(QString fa_google_drive READ get_fa_google_drive CONSTANT)
        Q_PROPERTY(QString fa_google_play READ get_fa_google_play CONSTANT)
        Q_PROPERTY(QString fa_google_plus READ get_fa_google_plus CONSTANT)
        Q_PROPERTY(QString fa_google_plus_g READ get_fa_google_plus_g CONSTANT)
        Q_PROPERTY(QString fa_google_plus_square READ get_fa_google_plus_square CONSTANT)
        Q_PROPERTY(QString fa_google_wallet READ get_fa_google_wallet CONSTANT)
        Q_PROPERTY(QString fa_gopuram READ get_fa_gopuram CONSTANT)
        Q_PROPERTY(QString fa_graduation_cap READ get_fa_graduation_cap CONSTANT)
        Q_PROPERTY(QString fa_gratipay READ get_fa_gratipay CONSTANT)
        Q_PROPERTY(QString fa_grav READ get_fa_grav CONSTANT)
        Q_PROPERTY(QString fa_greater_than READ get_fa_greater_than CONSTANT)
        Q_PROPERTY(QString fa_greater_than_equal READ get_fa_greater_than_equal CONSTANT)
        Q_PROPERTY(QString fa_grimace READ get_fa_grimace CONSTANT)
        Q_PROPERTY(QString fa_grin READ get_fa_grin CONSTANT)
        Q_PROPERTY(QString fa_grin_alt READ get_fa_grin_alt CONSTANT)
        Q_PROPERTY(QString fa_grin_beam READ get_fa_grin_beam CONSTANT)
        Q_PROPERTY(QString fa_grin_beam_sweat READ get_fa_grin_beam_sweat CONSTANT)
        Q_PROPERTY(QString fa_grin_hearts READ get_fa_grin_hearts CONSTANT)
        Q_PROPERTY(QString fa_grin_squint READ get_fa_grin_squint CONSTANT)
        Q_PROPERTY(QString fa_grin_squint_tears READ get_fa_grin_squint_tears CONSTANT)
        Q_PROPERTY(QString fa_grin_stars READ get_fa_grin_stars CONSTANT)
        Q_PROPERTY(QString fa_grin_tears READ get_fa_grin_tears CONSTANT)
        Q_PROPERTY(QString fa_grin_tongue READ get_fa_grin_tongue CONSTANT)
        Q_PROPERTY(QString fa_grin_tongue_squint READ get_fa_grin_tongue_squint CONSTANT)
        Q_PROPERTY(QString fa_grin_tongue_wink READ get_fa_grin_tongue_wink CONSTANT)
        Q_PROPERTY(QString fa_grin_wink READ get_fa_grin_wink CONSTANT)
        Q_PROPERTY(QString fa_grip_horizontal READ get_fa_grip_horizontal CONSTANT)
        Q_PROPERTY(QString fa_grip_lines READ get_fa_grip_lines CONSTANT)
        Q_PROPERTY(QString fa_grip_lines_vertical READ get_fa_grip_lines_vertical CONSTANT)
        Q_PROPERTY(QString fa_grip_vertical READ get_fa_grip_vertical CONSTANT)
        Q_PROPERTY(QString fa_gripfire READ get_fa_gripfire CONSTANT)
        Q_PROPERTY(QString fa_grunt READ get_fa_grunt CONSTANT)
        Q_PROPERTY(QString fa_guitar READ get_fa_guitar CONSTANT)
        Q_PROPERTY(QString fa_gulp READ get_fa_gulp CONSTANT)
        Q_PROPERTY(QString fa_h_square READ get_fa_h_square CONSTANT)
        Q_PROPERTY(QString fa_hacker_news READ get_fa_hacker_news CONSTANT)
        Q_PROPERTY(QString fa_hacker_news_square READ get_fa_hacker_news_square CONSTANT)
        Q_PROPERTY(QString fa_hackerrank READ get_fa_hackerrank CONSTANT)
        Q_PROPERTY(QString fa_hamburger READ get_fa_hamburger CONSTANT)
        Q_PROPERTY(QString fa_hammer READ get_fa_hammer CONSTANT)
        Q_PROPERTY(QString fa_hamsa READ get_fa_hamsa CONSTANT)
        Q_PROPERTY(QString fa_hand_holding READ get_fa_hand_holding CONSTANT)
        Q_PROPERTY(QString fa_hand_holding_heart READ get_fa_hand_holding_heart CONSTANT)
        Q_PROPERTY(QString fa_hand_holding_usd READ get_fa_hand_holding_usd CONSTANT)
        Q_PROPERTY(QString fa_hand_lizard READ get_fa_hand_lizard CONSTANT)
        Q_PROPERTY(QString fa_hand_middle_finger READ get_fa_hand_middle_finger CONSTANT)
        Q_PROPERTY(QString fa_hand_paper READ get_fa_hand_paper CONSTANT)
        Q_PROPERTY(QString fa_hand_peace READ get_fa_hand_peace CONSTANT)
        Q_PROPERTY(QString fa_hand_point_down READ get_fa_hand_point_down CONSTANT)
        Q_PROPERTY(QString fa_hand_point_left READ get_fa_hand_point_left CONSTANT)
        Q_PROPERTY(QString fa_hand_point_right READ get_fa_hand_point_right CONSTANT)
        Q_PROPERTY(QString fa_hand_point_up READ get_fa_hand_point_up CONSTANT)
        Q_PROPERTY(QString fa_hand_pointer READ get_fa_hand_pointer CONSTANT)
        Q_PROPERTY(QString fa_hand_rock READ get_fa_hand_rock CONSTANT)
        Q_PROPERTY(QString fa_hand_scissors READ get_fa_hand_scissors CONSTANT)
        Q_PROPERTY(QString fa_hand_spock READ get_fa_hand_spock CONSTANT)
        Q_PROPERTY(QString fa_hands READ get_fa_hands CONSTANT)
        Q_PROPERTY(QString fa_hands_helping READ get_fa_hands_helping CONSTANT)
        Q_PROPERTY(QString fa_handshake READ get_fa_handshake CONSTANT)
        Q_PROPERTY(QString fa_hanukiah READ get_fa_hanukiah CONSTANT)
        Q_PROPERTY(QString fa_hard_hat READ get_fa_hard_hat CONSTANT)
        Q_PROPERTY(QString fa_hashtag READ get_fa_hashtag CONSTANT)
        Q_PROPERTY(QString fa_hat_cowboy READ get_fa_hat_cowboy CONSTANT)
        Q_PROPERTY(QString fa_hat_cowboy_side READ get_fa_hat_cowboy_side CONSTANT)
        Q_PROPERTY(QString fa_hat_wizard READ get_fa_hat_wizard CONSTANT)
        Q_PROPERTY(QString fa_haykal READ get_fa_haykal CONSTANT)
        Q_PROPERTY(QString fa_hdd READ get_fa_hdd CONSTANT)
        Q_PROPERTY(QString fa_heading READ get_fa_heading CONSTANT)
        Q_PROPERTY(QString fa_headphones READ get_fa_headphones CONSTANT)
        Q_PROPERTY(QString fa_headphones_alt READ get_fa_headphones_alt CONSTANT)
        Q_PROPERTY(QString fa_headset READ get_fa_headset CONSTANT)
        Q_PROPERTY(QString fa_heart READ get_fa_heart CONSTANT)
        Q_PROPERTY(QString fa_heart_broken READ get_fa_heart_broken CONSTANT)
        Q_PROPERTY(QString fa_heartbeat READ get_fa_heartbeat CONSTANT)
        Q_PROPERTY(QString fa_helicopter READ get_fa_helicopter CONSTANT)
        Q_PROPERTY(QString fa_highlighter READ get_fa_highlighter CONSTANT)
        Q_PROPERTY(QString fa_hiking READ get_fa_hiking CONSTANT)
        Q_PROPERTY(QString fa_hippo READ get_fa_hippo CONSTANT)
        Q_PROPERTY(QString fa_hips READ get_fa_hips CONSTANT)
        Q_PROPERTY(QString fa_hire_a_helper READ get_fa_hire_a_helper CONSTANT)
        Q_PROPERTY(QString fa_history READ get_fa_history CONSTANT)
        Q_PROPERTY(QString fa_hockey_puck READ get_fa_hockey_puck CONSTANT)
        Q_PROPERTY(QString fa_holly_berry READ get_fa_holly_berry CONSTANT)
        Q_PROPERTY(QString fa_home READ get_fa_home CONSTANT)
        Q_PROPERTY(QString fa_hooli READ get_fa_hooli CONSTANT)
        Q_PROPERTY(QString fa_hornbill READ get_fa_hornbill CONSTANT)
        Q_PROPERTY(QString fa_horse READ get_fa_horse CONSTANT)
        Q_PROPERTY(QString fa_horse_head READ get_fa_horse_head CONSTANT)
        Q_PROPERTY(QString fa_hospital READ get_fa_hospital CONSTANT)
        Q_PROPERTY(QString fa_hospital_alt READ get_fa_hospital_alt CONSTANT)
        Q_PROPERTY(QString fa_hospital_symbol READ get_fa_hospital_symbol CONSTANT)
        Q_PROPERTY(QString fa_hot_tub READ get_fa_hot_tub CONSTANT)
        Q_PROPERTY(QString fa_hotdog READ get_fa_hotdog CONSTANT)
        Q_PROPERTY(QString fa_hotel READ get_fa_hotel CONSTANT)
        Q_PROPERTY(QString fa_hotjar READ get_fa_hotjar CONSTANT)
        Q_PROPERTY(QString fa_hourglass READ get_fa_hourglass CONSTANT)
        Q_PROPERTY(QString fa_hourglass_end READ get_fa_hourglass_end CONSTANT)
        Q_PROPERTY(QString fa_hourglass_half READ get_fa_hourglass_half CONSTANT)
        Q_PROPERTY(QString fa_hourglass_start READ get_fa_hourglass_start CONSTANT)
        Q_PROPERTY(QString fa_house_damage READ get_fa_house_damage CONSTANT)
        Q_PROPERTY(QString fa_houzz READ get_fa_houzz CONSTANT)
        Q_PROPERTY(QString fa_hryvnia READ get_fa_hryvnia CONSTANT)
        Q_PROPERTY(QString fa_html5 READ get_fa_html5 CONSTANT)
        Q_PROPERTY(QString fa_hubspot READ get_fa_hubspot CONSTANT)
        Q_PROPERTY(QString fa_i_cursor READ get_fa_i_cursor CONSTANT)
        Q_PROPERTY(QString fa_ice_cream READ get_fa_ice_cream CONSTANT)
        Q_PROPERTY(QString fa_icicles READ get_fa_icicles CONSTANT)
        Q_PROPERTY(QString fa_icons READ get_fa_icons CONSTANT)
        Q_PROPERTY(QString fa_id_badge READ get_fa_id_badge CONSTANT)
        Q_PROPERTY(QString fa_id_card READ get_fa_id_card CONSTANT)
        Q_PROPERTY(QString fa_id_card_alt READ get_fa_id_card_alt CONSTANT)
        Q_PROPERTY(QString fa_igloo READ get_fa_igloo CONSTANT)
        Q_PROPERTY(QString fa_image READ get_fa_image CONSTANT)
        Q_PROPERTY(QString fa_images READ get_fa_images CONSTANT)
        Q_PROPERTY(QString fa_imdb READ get_fa_imdb CONSTANT)
        Q_PROPERTY(QString fa_inbox READ get_fa_inbox CONSTANT)
        Q_PROPERTY(QString fa_indent READ get_fa_indent CONSTANT)
        Q_PROPERTY(QString fa_industry READ get_fa_industry CONSTANT)
        Q_PROPERTY(QString fa_infinity READ get_fa_infinity CONSTANT)
        Q_PROPERTY(QString fa_info READ get_fa_info CONSTANT)
        Q_PROPERTY(QString fa_info_circle READ get_fa_info_circle CONSTANT)
        Q_PROPERTY(QString fa_instagram READ get_fa_instagram CONSTANT)
        Q_PROPERTY(QString fa_intercom READ get_fa_intercom CONSTANT)
        Q_PROPERTY(QString fa_internet_explorer READ get_fa_internet_explorer CONSTANT)
        Q_PROPERTY(QString fa_invision READ get_fa_invision CONSTANT)
        Q_PROPERTY(QString fa_ioxhost READ get_fa_ioxhost CONSTANT)
        Q_PROPERTY(QString fa_italic READ get_fa_italic CONSTANT)
        Q_PROPERTY(QString fa_itch_io READ get_fa_itch_io CONSTANT)
        Q_PROPERTY(QString fa_itunes READ get_fa_itunes CONSTANT)
        Q_PROPERTY(QString fa_itunes_note READ get_fa_itunes_note CONSTANT)
        Q_PROPERTY(QString fa_java READ get_fa_java CONSTANT)
        Q_PROPERTY(QString fa_jedi READ get_fa_jedi CONSTANT)
        Q_PROPERTY(QString fa_jedi_order READ get_fa_jedi_order CONSTANT)
        Q_PROPERTY(QString fa_jenkins READ get_fa_jenkins CONSTANT)
        Q_PROPERTY(QString fa_jira READ get_fa_jira CONSTANT)
        Q_PROPERTY(QString fa_joget READ get_fa_joget CONSTANT)
        Q_PROPERTY(QString fa_joint READ get_fa_joint CONSTANT)
        Q_PROPERTY(QString fa_joomla READ get_fa_joomla CONSTANT)
        Q_PROPERTY(QString fa_journal_whills READ get_fa_journal_whills CONSTANT)
        Q_PROPERTY(QString fa_js READ get_fa_js CONSTANT)
        Q_PROPERTY(QString fa_js_square READ get_fa_js_square CONSTANT)
        Q_PROPERTY(QString fa_jsfiddle READ get_fa_jsfiddle CONSTANT)
        Q_PROPERTY(QString fa_kaaba READ get_fa_kaaba CONSTANT)
        Q_PROPERTY(QString fa_kaggle READ get_fa_kaggle CONSTANT)
        Q_PROPERTY(QString fa_key READ get_fa_key CONSTANT)
        Q_PROPERTY(QString fa_keybase READ get_fa_keybase CONSTANT)
        Q_PROPERTY(QString fa_keyboard READ get_fa_keyboard CONSTANT)
        Q_PROPERTY(QString fa_keycdn READ get_fa_keycdn CONSTANT)
        Q_PROPERTY(QString fa_khanda READ get_fa_khanda CONSTANT)
        Q_PROPERTY(QString fa_kickstarter READ get_fa_kickstarter CONSTANT)
        Q_PROPERTY(QString fa_kickstarter_k READ get_fa_kickstarter_k CONSTANT)
        Q_PROPERTY(QString fa_kiss READ get_fa_kiss CONSTANT)
        Q_PROPERTY(QString fa_kiss_beam READ get_fa_kiss_beam CONSTANT)
        Q_PROPERTY(QString fa_kiss_wink_heart READ get_fa_kiss_wink_heart CONSTANT)
        Q_PROPERTY(QString fa_kiwi_bird READ get_fa_kiwi_bird CONSTANT)
        Q_PROPERTY(QString fa_korvue READ get_fa_korvue CONSTANT)
        Q_PROPERTY(QString fa_landmark READ get_fa_landmark CONSTANT)
        Q_PROPERTY(QString fa_language READ get_fa_language CONSTANT)
        Q_PROPERTY(QString fa_laptop READ get_fa_laptop CONSTANT)
        Q_PROPERTY(QString fa_laptop_code READ get_fa_laptop_code CONSTANT)
        Q_PROPERTY(QString fa_laptop_medical READ get_fa_laptop_medical CONSTANT)
        Q_PROPERTY(QString fa_laravel READ get_fa_laravel CONSTANT)
        Q_PROPERTY(QString fa_lastfm READ get_fa_lastfm CONSTANT)
        Q_PROPERTY(QString fa_lastfm_square READ get_fa_lastfm_square CONSTANT)
        Q_PROPERTY(QString fa_laugh READ get_fa_laugh CONSTANT)
        Q_PROPERTY(QString fa_laugh_beam READ get_fa_laugh_beam CONSTANT)
        Q_PROPERTY(QString fa_laugh_squint READ get_fa_laugh_squint CONSTANT)
        Q_PROPERTY(QString fa_laugh_wink READ get_fa_laugh_wink CONSTANT)
        Q_PROPERTY(QString fa_layer_group READ get_fa_layer_group CONSTANT)
        Q_PROPERTY(QString fa_leaf READ get_fa_leaf CONSTANT)
        Q_PROPERTY(QString fa_leanpub READ get_fa_leanpub CONSTANT)
        Q_PROPERTY(QString fa_lemon READ get_fa_lemon CONSTANT)
        Q_PROPERTY(QString fa_less READ get_fa_less CONSTANT)
        Q_PROPERTY(QString fa_less_than READ get_fa_less_than CONSTANT)
        Q_PROPERTY(QString fa_less_than_equal READ get_fa_less_than_equal CONSTANT)
        Q_PROPERTY(QString fa_level_down_alt READ get_fa_level_down_alt CONSTANT)
        Q_PROPERTY(QString fa_level_up_alt READ get_fa_level_up_alt CONSTANT)
        Q_PROPERTY(QString fa_life_ring READ get_fa_life_ring CONSTANT)
        Q_PROPERTY(QString fa_lightbulb READ get_fa_lightbulb CONSTANT)
        Q_PROPERTY(QString fa_line READ get_fa_line CONSTANT)
        Q_PROPERTY(QString fa_link READ get_fa_link CONSTANT)
        Q_PROPERTY(QString fa_linkedin READ get_fa_linkedin CONSTANT)
        Q_PROPERTY(QString fa_linkedin_in READ get_fa_linkedin_in CONSTANT)
        Q_PROPERTY(QString fa_linode READ get_fa_linode CONSTANT)
        Q_PROPERTY(QString fa_linux READ get_fa_linux CONSTANT)
        Q_PROPERTY(QString fa_lira_sign READ get_fa_lira_sign CONSTANT)
        Q_PROPERTY(QString fa_list READ get_fa_list CONSTANT)
        Q_PROPERTY(QString fa_list_alt READ get_fa_list_alt CONSTANT)
        Q_PROPERTY(QString fa_list_ol READ get_fa_list_ol CONSTANT)
        Q_PROPERTY(QString fa_list_ul READ get_fa_list_ul CONSTANT)
        Q_PROPERTY(QString fa_location_arrow READ get_fa_location_arrow CONSTANT)
        Q_PROPERTY(QString fa_lock READ get_fa_lock CONSTANT)
        Q_PROPERTY(QString fa_lock_open READ get_fa_lock_open CONSTANT)
        Q_PROPERTY(QString fa_long_arrow_alt_down READ get_fa_long_arrow_alt_down CONSTANT)
        Q_PROPERTY(QString fa_long_arrow_alt_left READ get_fa_long_arrow_alt_left CONSTANT)
        Q_PROPERTY(QString fa_long_arrow_alt_right READ get_fa_long_arrow_alt_right CONSTANT)
        Q_PROPERTY(QString fa_long_arrow_alt_up READ get_fa_long_arrow_alt_up CONSTANT)
        Q_PROPERTY(QString fa_low_vision READ get_fa_low_vision CONSTANT)
        Q_PROPERTY(QString fa_luggage_cart READ get_fa_luggage_cart CONSTANT)
        Q_PROPERTY(QString fa_lyft READ get_fa_lyft CONSTANT)
        Q_PROPERTY(QString fa_magento READ get_fa_magento CONSTANT)
        Q_PROPERTY(QString fa_magic READ get_fa_magic CONSTANT)
        Q_PROPERTY(QString fa_magnet READ get_fa_magnet CONSTANT)
        Q_PROPERTY(QString fa_mail_bulk READ get_fa_mail_bulk CONSTANT)
        Q_PROPERTY(QString fa_mailchimp READ get_fa_mailchimp CONSTANT)
        Q_PROPERTY(QString fa_male READ get_fa_male CONSTANT)
        Q_PROPERTY(QString fa_mandalorian READ get_fa_mandalorian CONSTANT)
        Q_PROPERTY(QString fa_map READ get_fa_map CONSTANT)
        Q_PROPERTY(QString fa_map_marked READ get_fa_map_marked CONSTANT)
        Q_PROPERTY(QString fa_map_marked_alt READ get_fa_map_marked_alt CONSTANT)
        Q_PROPERTY(QString fa_map_marker READ get_fa_map_marker CONSTANT)
        Q_PROPERTY(QString fa_map_marker_alt READ get_fa_map_marker_alt CONSTANT)
        Q_PROPERTY(QString fa_map_pin READ get_fa_map_pin CONSTANT)
        Q_PROPERTY(QString fa_map_signs READ get_fa_map_signs CONSTANT)
        Q_PROPERTY(QString fa_markdown READ get_fa_markdown CONSTANT)
        Q_PROPERTY(QString fa_marker READ get_fa_marker CONSTANT)
        Q_PROPERTY(QString fa_mars READ get_fa_mars CONSTANT)
        Q_PROPERTY(QString fa_mars_double READ get_fa_mars_double CONSTANT)
        Q_PROPERTY(QString fa_mars_stroke READ get_fa_mars_stroke CONSTANT)
        Q_PROPERTY(QString fa_mars_stroke_h READ get_fa_mars_stroke_h CONSTANT)
        Q_PROPERTY(QString fa_mars_stroke_v READ get_fa_mars_stroke_v CONSTANT)
        Q_PROPERTY(QString fa_mask READ get_fa_mask CONSTANT)
        Q_PROPERTY(QString fa_mastodon READ get_fa_mastodon CONSTANT)
        Q_PROPERTY(QString fa_maxcdn READ get_fa_maxcdn CONSTANT)
        Q_PROPERTY(QString fa_mdb READ get_fa_mdb CONSTANT)
        Q_PROPERTY(QString fa_medal READ get_fa_medal CONSTANT)
        Q_PROPERTY(QString fa_medapps READ get_fa_medapps CONSTANT)
        Q_PROPERTY(QString fa_medium READ get_fa_medium CONSTANT)
        Q_PROPERTY(QString fa_medium_m READ get_fa_medium_m CONSTANT)
        Q_PROPERTY(QString fa_medkit READ get_fa_medkit CONSTANT)
        Q_PROPERTY(QString fa_medrt READ get_fa_medrt CONSTANT)
        Q_PROPERTY(QString fa_meetup READ get_fa_meetup CONSTANT)
        Q_PROPERTY(QString fa_megaport READ get_fa_megaport CONSTANT)
        Q_PROPERTY(QString fa_meh READ get_fa_meh CONSTANT)
        Q_PROPERTY(QString fa_meh_blank READ get_fa_meh_blank CONSTANT)
        Q_PROPERTY(QString fa_meh_rolling_eyes READ get_fa_meh_rolling_eyes CONSTANT)
        Q_PROPERTY(QString fa_memory READ get_fa_memory CONSTANT)
        Q_PROPERTY(QString fa_mendeley READ get_fa_mendeley CONSTANT)
        Q_PROPERTY(QString fa_menorah READ get_fa_menorah CONSTANT)
        Q_PROPERTY(QString fa_mercury READ get_fa_mercury CONSTANT)
        Q_PROPERTY(QString fa_meteor READ get_fa_meteor CONSTANT)
        Q_PROPERTY(QString fa_microchip READ get_fa_microchip CONSTANT)
        Q_PROPERTY(QString fa_microphone READ get_fa_microphone CONSTANT)
        Q_PROPERTY(QString fa_microphone_alt READ get_fa_microphone_alt CONSTANT)
        Q_PROPERTY(QString fa_microphone_alt_slash READ get_fa_microphone_alt_slash CONSTANT)
        Q_PROPERTY(QString fa_microphone_slash READ get_fa_microphone_slash CONSTANT)
        Q_PROPERTY(QString fa_microscope READ get_fa_microscope CONSTANT)
        Q_PROPERTY(QString fa_microsoft READ get_fa_microsoft CONSTANT)
        Q_PROPERTY(QString fa_minus READ get_fa_minus CONSTANT)
        Q_PROPERTY(QString fa_minus_circle READ get_fa_minus_circle CONSTANT)
        Q_PROPERTY(QString fa_minus_square READ get_fa_minus_square CONSTANT)
        Q_PROPERTY(QString fa_mitten READ get_fa_mitten CONSTANT)
        Q_PROPERTY(QString fa_mix READ get_fa_mix CONSTANT)
        Q_PROPERTY(QString fa_mixcloud READ get_fa_mixcloud CONSTANT)
        Q_PROPERTY(QString fa_mizuni READ get_fa_mizuni CONSTANT)
        Q_PROPERTY(QString fa_mobile READ get_fa_mobile CONSTANT)
        Q_PROPERTY(QString fa_mobile_alt READ get_fa_mobile_alt CONSTANT)
        Q_PROPERTY(QString fa_modx READ get_fa_modx CONSTANT)
        Q_PROPERTY(QString fa_monero READ get_fa_monero CONSTANT)
        Q_PROPERTY(QString fa_money_bill READ get_fa_money_bill CONSTANT)
        Q_PROPERTY(QString fa_money_bill_alt READ get_fa_money_bill_alt CONSTANT)
        Q_PROPERTY(QString fa_money_bill_wave READ get_fa_money_bill_wave CONSTANT)
        Q_PROPERTY(QString fa_money_bill_wave_alt READ get_fa_money_bill_wave_alt CONSTANT)
        Q_PROPERTY(QString fa_money_check READ get_fa_money_check CONSTANT)
        Q_PROPERTY(QString fa_money_check_alt READ get_fa_money_check_alt CONSTANT)
        Q_PROPERTY(QString fa_monument READ get_fa_monument CONSTANT)
        Q_PROPERTY(QString fa_moon READ get_fa_moon CONSTANT)
        Q_PROPERTY(QString fa_mortar_pestle READ get_fa_mortar_pestle CONSTANT)
        Q_PROPERTY(QString fa_mosque READ get_fa_mosque CONSTANT)
        Q_PROPERTY(QString fa_motorcycle READ get_fa_motorcycle CONSTANT)
        Q_PROPERTY(QString fa_mountain READ get_fa_mountain CONSTANT)
        Q_PROPERTY(QString fa_mouse READ get_fa_mouse CONSTANT)
        Q_PROPERTY(QString fa_mouse_pointer READ get_fa_mouse_pointer CONSTANT)
        Q_PROPERTY(QString fa_mug_hot READ get_fa_mug_hot CONSTANT)
        Q_PROPERTY(QString fa_music READ get_fa_music CONSTANT)
        Q_PROPERTY(QString fa_napster READ get_fa_napster CONSTANT)
        Q_PROPERTY(QString fa_neos READ get_fa_neos CONSTANT)
        Q_PROPERTY(QString fa_network_wired READ get_fa_network_wired CONSTANT)
        Q_PROPERTY(QString fa_neuter READ get_fa_neuter CONSTANT)
        Q_PROPERTY(QString fa_newspaper READ get_fa_newspaper CONSTANT)
        Q_PROPERTY(QString fa_nimblr READ get_fa_nimblr CONSTANT)
        Q_PROPERTY(QString fa_node READ get_fa_node CONSTANT)
        Q_PROPERTY(QString fa_node_js READ get_fa_node_js CONSTANT)
        Q_PROPERTY(QString fa_not_equal READ get_fa_not_equal CONSTANT)
        Q_PROPERTY(QString fa_notes_medical READ get_fa_notes_medical CONSTANT)
        Q_PROPERTY(QString fa_npm READ get_fa_npm CONSTANT)
        Q_PROPERTY(QString fa_ns8 READ get_fa_ns8 CONSTANT)
        Q_PROPERTY(QString fa_nutritionix READ get_fa_nutritionix CONSTANT)
        Q_PROPERTY(QString fa_object_group READ get_fa_object_group CONSTANT)
        Q_PROPERTY(QString fa_object_ungroup READ get_fa_object_ungroup CONSTANT)
        Q_PROPERTY(QString fa_odnoklassniki READ get_fa_odnoklassniki CONSTANT)
        Q_PROPERTY(QString fa_odnoklassniki_square READ get_fa_odnoklassniki_square CONSTANT)
        Q_PROPERTY(QString fa_oil_can READ get_fa_oil_can CONSTANT)
        Q_PROPERTY(QString fa_old_republic READ get_fa_old_republic CONSTANT)
        Q_PROPERTY(QString fa_om READ get_fa_om CONSTANT)
        Q_PROPERTY(QString fa_opencart READ get_fa_opencart CONSTANT)
        Q_PROPERTY(QString fa_openid READ get_fa_openid CONSTANT)
        Q_PROPERTY(QString fa_opera READ get_fa_opera CONSTANT)
        Q_PROPERTY(QString fa_optin_monster READ get_fa_optin_monster CONSTANT)
        Q_PROPERTY(QString fa_orcid READ get_fa_orcid CONSTANT)
        Q_PROPERTY(QString fa_osi READ get_fa_osi CONSTANT)
        Q_PROPERTY(QString fa_otter READ get_fa_otter CONSTANT)
        Q_PROPERTY(QString fa_outdent READ get_fa_outdent CONSTANT)
        Q_PROPERTY(QString fa_page4 READ get_fa_page4 CONSTANT)
        Q_PROPERTY(QString fa_pagelines READ get_fa_pagelines CONSTANT)
        Q_PROPERTY(QString fa_pager READ get_fa_pager CONSTANT)
        Q_PROPERTY(QString fa_paint_brush READ get_fa_paint_brush CONSTANT)
        Q_PROPERTY(QString fa_paint_roller READ get_fa_paint_roller CONSTANT)
        Q_PROPERTY(QString fa_palette READ get_fa_palette CONSTANT)
        Q_PROPERTY(QString fa_palfed READ get_fa_palfed CONSTANT)
        Q_PROPERTY(QString fa_pallet READ get_fa_pallet CONSTANT)
        Q_PROPERTY(QString fa_paper_plane READ get_fa_paper_plane CONSTANT)
        Q_PROPERTY(QString fa_paperclip READ get_fa_paperclip CONSTANT)
        Q_PROPERTY(QString fa_parachute_box READ get_fa_parachute_box CONSTANT)
        Q_PROPERTY(QString fa_paragraph READ get_fa_paragraph CONSTANT)
        Q_PROPERTY(QString fa_parking READ get_fa_parking CONSTANT)
        Q_PROPERTY(QString fa_passport READ get_fa_passport CONSTANT)
        Q_PROPERTY(QString fa_pastafarianism READ get_fa_pastafarianism CONSTANT)
        Q_PROPERTY(QString fa_paste READ get_fa_paste CONSTANT)
        Q_PROPERTY(QString fa_patreon READ get_fa_patreon CONSTANT)
        Q_PROPERTY(QString fa_pause READ get_fa_pause CONSTANT)
        Q_PROPERTY(QString fa_pause_circle READ get_fa_pause_circle CONSTANT)
        Q_PROPERTY(QString fa_paw READ get_fa_paw CONSTANT)
        Q_PROPERTY(QString fa_paypal READ get_fa_paypal CONSTANT)
        Q_PROPERTY(QString fa_peace READ get_fa_peace CONSTANT)
        Q_PROPERTY(QString fa_pen READ get_fa_pen CONSTANT)
        Q_PROPERTY(QString fa_pen_alt READ get_fa_pen_alt CONSTANT)
        Q_PROPERTY(QString fa_pen_fancy READ get_fa_pen_fancy CONSTANT)
        Q_PROPERTY(QString fa_pen_nib READ get_fa_pen_nib CONSTANT)
        Q_PROPERTY(QString fa_pen_square READ get_fa_pen_square CONSTANT)
        Q_PROPERTY(QString fa_pencil_alt READ get_fa_pencil_alt CONSTANT)
        Q_PROPERTY(QString fa_pencil_ruler READ get_fa_pencil_ruler CONSTANT)
        Q_PROPERTY(QString fa_penny_arcade READ get_fa_penny_arcade CONSTANT)
        Q_PROPERTY(QString fa_people_carry READ get_fa_people_carry CONSTANT)
        Q_PROPERTY(QString fa_pepper_hot READ get_fa_pepper_hot CONSTANT)
        Q_PROPERTY(QString fa_percent READ get_fa_percent CONSTANT)
        Q_PROPERTY(QString fa_percentage READ get_fa_percentage CONSTANT)
        Q_PROPERTY(QString fa_periscope READ get_fa_periscope CONSTANT)
        Q_PROPERTY(QString fa_person_booth READ get_fa_person_booth CONSTANT)
        Q_PROPERTY(QString fa_phabricator READ get_fa_phabricator CONSTANT)
        Q_PROPERTY(QString fa_phoenix_framework READ get_fa_phoenix_framework CONSTANT)
        Q_PROPERTY(QString fa_phoenix_squadron READ get_fa_phoenix_squadron CONSTANT)
        Q_PROPERTY(QString fa_phone READ get_fa_phone CONSTANT)
        Q_PROPERTY(QString fa_phone_alt READ get_fa_phone_alt CONSTANT)
        Q_PROPERTY(QString fa_phone_slash READ get_fa_phone_slash CONSTANT)
        Q_PROPERTY(QString fa_phone_square READ get_fa_phone_square CONSTANT)
        Q_PROPERTY(QString fa_phone_square_alt READ get_fa_phone_square_alt CONSTANT)
        Q_PROPERTY(QString fa_phone_volume READ get_fa_phone_volume CONSTANT)
        Q_PROPERTY(QString fa_photo_video READ get_fa_photo_video CONSTANT)
        Q_PROPERTY(QString fa_php READ get_fa_php CONSTANT)
        Q_PROPERTY(QString fa_pied_piper READ get_fa_pied_piper CONSTANT)
        Q_PROPERTY(QString fa_pied_piper_alt READ get_fa_pied_piper_alt CONSTANT)
        Q_PROPERTY(QString fa_pied_piper_hat READ get_fa_pied_piper_hat CONSTANT)
        Q_PROPERTY(QString fa_pied_piper_pp READ get_fa_pied_piper_pp CONSTANT)
        Q_PROPERTY(QString fa_piggy_bank READ get_fa_piggy_bank CONSTANT)
        Q_PROPERTY(QString fa_pills READ get_fa_pills CONSTANT)
        Q_PROPERTY(QString fa_pinterest READ get_fa_pinterest CONSTANT)
        Q_PROPERTY(QString fa_pinterest_p READ get_fa_pinterest_p CONSTANT)
        Q_PROPERTY(QString fa_pinterest_square READ get_fa_pinterest_square CONSTANT)
        Q_PROPERTY(QString fa_pizza_slice READ get_fa_pizza_slice CONSTANT)
        Q_PROPERTY(QString fa_place_of_worship READ get_fa_place_of_worship CONSTANT)
        Q_PROPERTY(QString fa_plane READ get_fa_plane CONSTANT)
        Q_PROPERTY(QString fa_plane_arrival READ get_fa_plane_arrival CONSTANT)
        Q_PROPERTY(QString fa_plane_departure READ get_fa_plane_departure CONSTANT)
        Q_PROPERTY(QString fa_play READ get_fa_play CONSTANT)
        Q_PROPERTY(QString fa_play_circle READ get_fa_play_circle CONSTANT)
        Q_PROPERTY(QString fa_playstation READ get_fa_playstation CONSTANT)
        Q_PROPERTY(QString fa_plug READ get_fa_plug CONSTANT)
        Q_PROPERTY(QString fa_plus READ get_fa_plus CONSTANT)
        Q_PROPERTY(QString fa_plus_circle READ get_fa_plus_circle CONSTANT)
        Q_PROPERTY(QString fa_plus_square READ get_fa_plus_square CONSTANT)
        Q_PROPERTY(QString fa_podcast READ get_fa_podcast CONSTANT)
        Q_PROPERTY(QString fa_poll READ get_fa_poll CONSTANT)
        Q_PROPERTY(QString fa_poll_h READ get_fa_poll_h CONSTANT)
        Q_PROPERTY(QString fa_poo READ get_fa_poo CONSTANT)
        Q_PROPERTY(QString fa_poo_storm READ get_fa_poo_storm CONSTANT)
        Q_PROPERTY(QString fa_poop READ get_fa_poop CONSTANT)
        Q_PROPERTY(QString fa_portrait READ get_fa_portrait CONSTANT)
        Q_PROPERTY(QString fa_pound_sign READ get_fa_pound_sign CONSTANT)
        Q_PROPERTY(QString fa_power_off READ get_fa_power_off CONSTANT)
        Q_PROPERTY(QString fa_pray READ get_fa_pray CONSTANT)
        Q_PROPERTY(QString fa_praying_hands READ get_fa_praying_hands CONSTANT)
        Q_PROPERTY(QString fa_prescription READ get_fa_prescription CONSTANT)
        Q_PROPERTY(QString fa_prescription_bottle READ get_fa_prescription_bottle CONSTANT)
        Q_PROPERTY(QString fa_prescription_bottle_alt READ get_fa_prescription_bottle_alt CONSTANT)
        Q_PROPERTY(QString fa_print READ get_fa_print CONSTANT)
        Q_PROPERTY(QString fa_procedures READ get_fa_procedures CONSTANT)
        Q_PROPERTY(QString fa_product_hunt READ get_fa_product_hunt CONSTANT)
        Q_PROPERTY(QString fa_project_diagram READ get_fa_project_diagram CONSTANT)
        Q_PROPERTY(QString fa_pushed READ get_fa_pushed CONSTANT)
        Q_PROPERTY(QString fa_puzzle_piece READ get_fa_puzzle_piece CONSTANT)
        Q_PROPERTY(QString fa_python READ get_fa_python CONSTANT)
        Q_PROPERTY(QString fa_qq READ get_fa_qq CONSTANT)
        Q_PROPERTY(QString fa_qrcode READ get_fa_qrcode CONSTANT)
        Q_PROPERTY(QString fa_question READ get_fa_question CONSTANT)
        Q_PROPERTY(QString fa_question_circle READ get_fa_question_circle CONSTANT)
        Q_PROPERTY(QString fa_quidditch READ get_fa_quidditch CONSTANT)
        Q_PROPERTY(QString fa_quinscape READ get_fa_quinscape CONSTANT)
        Q_PROPERTY(QString fa_quora READ get_fa_quora CONSTANT)
        Q_PROPERTY(QString fa_quote_left READ get_fa_quote_left CONSTANT)
        Q_PROPERTY(QString fa_quote_right READ get_fa_quote_right CONSTANT)
        Q_PROPERTY(QString fa_quran READ get_fa_quran CONSTANT)
        Q_PROPERTY(QString fa_r_project READ get_fa_r_project CONSTANT)
        Q_PROPERTY(QString fa_radiation READ get_fa_radiation CONSTANT)
        Q_PROPERTY(QString fa_radiation_alt READ get_fa_radiation_alt CONSTANT)
        Q_PROPERTY(QString fa_rainbow READ get_fa_rainbow CONSTANT)
        Q_PROPERTY(QString fa_random READ get_fa_random CONSTANT)
        Q_PROPERTY(QString fa_raspberry_pi READ get_fa_raspberry_pi CONSTANT)
        Q_PROPERTY(QString fa_ravelry READ get_fa_ravelry CONSTANT)
        Q_PROPERTY(QString fa_react READ get_fa_react CONSTANT)
        Q_PROPERTY(QString fa_reacteurope READ get_fa_reacteurope CONSTANT)
        Q_PROPERTY(QString fa_readme READ get_fa_readme CONSTANT)
        Q_PROPERTY(QString fa_rebel READ get_fa_rebel CONSTANT)
        Q_PROPERTY(QString fa_receipt READ get_fa_receipt CONSTANT)
        Q_PROPERTY(QString fa_record_vinyl READ get_fa_record_vinyl CONSTANT)
        Q_PROPERTY(QString fa_recycle READ get_fa_recycle CONSTANT)
        Q_PROPERTY(QString fa_red_river READ get_fa_red_river CONSTANT)
        Q_PROPERTY(QString fa_reddit READ get_fa_reddit CONSTANT)
        Q_PROPERTY(QString fa_reddit_alien READ get_fa_reddit_alien CONSTANT)
        Q_PROPERTY(QString fa_reddit_square READ get_fa_reddit_square CONSTANT)
        Q_PROPERTY(QString fa_redhat READ get_fa_redhat CONSTANT)
        Q_PROPERTY(QString fa_redo READ get_fa_redo CONSTANT)
        Q_PROPERTY(QString fa_redo_alt READ get_fa_redo_alt CONSTANT)
        Q_PROPERTY(QString fa_registered READ get_fa_registered CONSTANT)
        Q_PROPERTY(QString fa_remove_format READ get_fa_remove_format CONSTANT)
        Q_PROPERTY(QString fa_renren READ get_fa_renren CONSTANT)
        Q_PROPERTY(QString fa_reply READ get_fa_reply CONSTANT)
        Q_PROPERTY(QString fa_reply_all READ get_fa_reply_all CONSTANT)
        Q_PROPERTY(QString fa_replyd READ get_fa_replyd CONSTANT)
        Q_PROPERTY(QString fa_republican READ get_fa_republican CONSTANT)
        Q_PROPERTY(QString fa_researchgate READ get_fa_researchgate CONSTANT)
        Q_PROPERTY(QString fa_resolving READ get_fa_resolving CONSTANT)
        Q_PROPERTY(QString fa_restroom READ get_fa_restroom CONSTANT)
        Q_PROPERTY(QString fa_retweet READ get_fa_retweet CONSTANT)
        Q_PROPERTY(QString fa_rev READ get_fa_rev CONSTANT)
        Q_PROPERTY(QString fa_ribbon READ get_fa_ribbon CONSTANT)
        Q_PROPERTY(QString fa_ring READ get_fa_ring CONSTANT)
        Q_PROPERTY(QString fa_road READ get_fa_road CONSTANT)
        Q_PROPERTY(QString fa_robot READ get_fa_robot CONSTANT)
        Q_PROPERTY(QString fa_rocket READ get_fa_rocket CONSTANT)
        Q_PROPERTY(QString fa_rocketchat READ get_fa_rocketchat CONSTANT)
        Q_PROPERTY(QString fa_rockrms READ get_fa_rockrms CONSTANT)
        Q_PROPERTY(QString fa_route READ get_fa_route CONSTANT)
        Q_PROPERTY(QString fa_rss READ get_fa_rss CONSTANT)
        Q_PROPERTY(QString fa_rss_square READ get_fa_rss_square CONSTANT)
        Q_PROPERTY(QString fa_ruble_sign READ get_fa_ruble_sign CONSTANT)
        Q_PROPERTY(QString fa_ruler READ get_fa_ruler CONSTANT)
        Q_PROPERTY(QString fa_ruler_combined READ get_fa_ruler_combined CONSTANT)
        Q_PROPERTY(QString fa_ruler_horizontal READ get_fa_ruler_horizontal CONSTANT)
        Q_PROPERTY(QString fa_ruler_vertical READ get_fa_ruler_vertical CONSTANT)
        Q_PROPERTY(QString fa_running READ get_fa_running CONSTANT)
        Q_PROPERTY(QString fa_rupee_sign READ get_fa_rupee_sign CONSTANT)
        Q_PROPERTY(QString fa_sad_cry READ get_fa_sad_cry CONSTANT)
        Q_PROPERTY(QString fa_sad_tear READ get_fa_sad_tear CONSTANT)
        Q_PROPERTY(QString fa_safari READ get_fa_safari CONSTANT)
        Q_PROPERTY(QString fa_salesforce READ get_fa_salesforce CONSTANT)
        Q_PROPERTY(QString fa_sass READ get_fa_sass CONSTANT)
        Q_PROPERTY(QString fa_satellite READ get_fa_satellite CONSTANT)
        Q_PROPERTY(QString fa_satellite_dish READ get_fa_satellite_dish CONSTANT)
        Q_PROPERTY(QString fa_save READ get_fa_save CONSTANT)
        Q_PROPERTY(QString fa_schlix READ get_fa_schlix CONSTANT)
        Q_PROPERTY(QString fa_school READ get_fa_school CONSTANT)
        Q_PROPERTY(QString fa_screwdriver READ get_fa_screwdriver CONSTANT)
        Q_PROPERTY(QString fa_scribd READ get_fa_scribd CONSTANT)
        Q_PROPERTY(QString fa_scroll READ get_fa_scroll CONSTANT)
        Q_PROPERTY(QString fa_sd_card READ get_fa_sd_card CONSTANT)
        Q_PROPERTY(QString fa_search READ get_fa_search CONSTANT)
        Q_PROPERTY(QString fa_search_dollar READ get_fa_search_dollar CONSTANT)
        Q_PROPERTY(QString fa_search_location READ get_fa_search_location CONSTANT)
        Q_PROPERTY(QString fa_search_minus READ get_fa_search_minus CONSTANT)
        Q_PROPERTY(QString fa_search_plus READ get_fa_search_plus CONSTANT)
        Q_PROPERTY(QString fa_searchengin READ get_fa_searchengin CONSTANT)
        Q_PROPERTY(QString fa_seedling READ get_fa_seedling CONSTANT)
        Q_PROPERTY(QString fa_sellcast READ get_fa_sellcast CONSTANT)
        Q_PROPERTY(QString fa_sellsy READ get_fa_sellsy CONSTANT)
        Q_PROPERTY(QString fa_server READ get_fa_server CONSTANT)
        Q_PROPERTY(QString fa_servicestack READ get_fa_servicestack CONSTANT)
        Q_PROPERTY(QString fa_shapes READ get_fa_shapes CONSTANT)
        Q_PROPERTY(QString fa_share READ get_fa_share CONSTANT)
        Q_PROPERTY(QString fa_share_alt READ get_fa_share_alt CONSTANT)
        Q_PROPERTY(QString fa_share_alt_square READ get_fa_share_alt_square CONSTANT)
        Q_PROPERTY(QString fa_share_square READ get_fa_share_square CONSTANT)
        Q_PROPERTY(QString fa_shekel_sign READ get_fa_shekel_sign CONSTANT)
        Q_PROPERTY(QString fa_shield_alt READ get_fa_shield_alt CONSTANT)
        Q_PROPERTY(QString fa_ship READ get_fa_ship CONSTANT)
        Q_PROPERTY(QString fa_shipping_fast READ get_fa_shipping_fast CONSTANT)
        Q_PROPERTY(QString fa_shirtsinbulk READ get_fa_shirtsinbulk CONSTANT)
        Q_PROPERTY(QString fa_shoe_prints READ get_fa_shoe_prints CONSTANT)
        Q_PROPERTY(QString fa_shopping_bag READ get_fa_shopping_bag CONSTANT)
        Q_PROPERTY(QString fa_shopping_basket READ get_fa_shopping_basket CONSTANT)
        Q_PROPERTY(QString fa_shopping_cart READ get_fa_shopping_cart CONSTANT)
        Q_PROPERTY(QString fa_shopware READ get_fa_shopware CONSTANT)
        Q_PROPERTY(QString fa_shower READ get_fa_shower CONSTANT)
        Q_PROPERTY(QString fa_shuttle_van READ get_fa_shuttle_van CONSTANT)
        Q_PROPERTY(QString fa_sign READ get_fa_sign CONSTANT)
        Q_PROPERTY(QString fa_sign_in_alt READ get_fa_sign_in_alt CONSTANT)
        Q_PROPERTY(QString fa_sign_language READ get_fa_sign_language CONSTANT)
        Q_PROPERTY(QString fa_sign_out_alt READ get_fa_sign_out_alt CONSTANT)
        Q_PROPERTY(QString fa_signal READ get_fa_signal CONSTANT)
        Q_PROPERTY(QString fa_signature READ get_fa_signature CONSTANT)
        Q_PROPERTY(QString fa_sim_card READ get_fa_sim_card CONSTANT)
        Q_PROPERTY(QString fa_simplybuilt READ get_fa_simplybuilt CONSTANT)
        Q_PROPERTY(QString fa_sistrix READ get_fa_sistrix CONSTANT)
        Q_PROPERTY(QString fa_sitemap READ get_fa_sitemap CONSTANT)
        Q_PROPERTY(QString fa_sith READ get_fa_sith CONSTANT)
        Q_PROPERTY(QString fa_skating READ get_fa_skating CONSTANT)
        Q_PROPERTY(QString fa_sketch READ get_fa_sketch CONSTANT)
        Q_PROPERTY(QString fa_skiing READ get_fa_skiing CONSTANT)
        Q_PROPERTY(QString fa_skiing_nordic READ get_fa_skiing_nordic CONSTANT)
        Q_PROPERTY(QString fa_skull READ get_fa_skull CONSTANT)
        Q_PROPERTY(QString fa_skull_crossbones READ get_fa_skull_crossbones CONSTANT)
        Q_PROPERTY(QString fa_skyatlas READ get_fa_skyatlas CONSTANT)
        Q_PROPERTY(QString fa_skype READ get_fa_skype CONSTANT)
        Q_PROPERTY(QString fa_slack READ get_fa_slack CONSTANT)
        Q_PROPERTY(QString fa_slack_hash READ get_fa_slack_hash CONSTANT)
        Q_PROPERTY(QString fa_slash READ get_fa_slash CONSTANT)
        Q_PROPERTY(QString fa_sleigh READ get_fa_sleigh CONSTANT)
        Q_PROPERTY(QString fa_sliders_h READ get_fa_sliders_h CONSTANT)
        Q_PROPERTY(QString fa_slideshare READ get_fa_slideshare CONSTANT)
        Q_PROPERTY(QString fa_smile READ get_fa_smile CONSTANT)
        Q_PROPERTY(QString fa_smile_beam READ get_fa_smile_beam CONSTANT)
        Q_PROPERTY(QString fa_smile_wink READ get_fa_smile_wink CONSTANT)
        Q_PROPERTY(QString fa_smog READ get_fa_smog CONSTANT)
        Q_PROPERTY(QString fa_smoking READ get_fa_smoking CONSTANT)
        Q_PROPERTY(QString fa_smoking_ban READ get_fa_smoking_ban CONSTANT)
        Q_PROPERTY(QString fa_sms READ get_fa_sms CONSTANT)
        Q_PROPERTY(QString fa_snapchat READ get_fa_snapchat CONSTANT)
        Q_PROPERTY(QString fa_snapchat_ghost READ get_fa_snapchat_ghost CONSTANT)
        Q_PROPERTY(QString fa_snapchat_square READ get_fa_snapchat_square CONSTANT)
        Q_PROPERTY(QString fa_snowboarding READ get_fa_snowboarding CONSTANT)
        Q_PROPERTY(QString fa_snowflake READ get_fa_snowflake CONSTANT)
        Q_PROPERTY(QString fa_snowman READ get_fa_snowman CONSTANT)
        Q_PROPERTY(QString fa_snowplow READ get_fa_snowplow CONSTANT)
        Q_PROPERTY(QString fa_socks READ get_fa_socks CONSTANT)
        Q_PROPERTY(QString fa_solar_panel READ get_fa_solar_panel CONSTANT)
        Q_PROPERTY(QString fa_sort READ get_fa_sort CONSTANT)
        Q_PROPERTY(QString fa_sort_alpha_down READ get_fa_sort_alpha_down CONSTANT)
        Q_PROPERTY(QString fa_sort_alpha_down_alt READ get_fa_sort_alpha_down_alt CONSTANT)
        Q_PROPERTY(QString fa_sort_alpha_up READ get_fa_sort_alpha_up CONSTANT)
        Q_PROPERTY(QString fa_sort_alpha_up_alt READ get_fa_sort_alpha_up_alt CONSTANT)
        Q_PROPERTY(QString fa_sort_amount_down READ get_fa_sort_amount_down CONSTANT)
        Q_PROPERTY(QString fa_sort_amount_down_alt READ get_fa_sort_amount_down_alt CONSTANT)
        Q_PROPERTY(QString fa_sort_amount_up READ get_fa_sort_amount_up CONSTANT)
        Q_PROPERTY(QString fa_sort_amount_up_alt READ get_fa_sort_amount_up_alt CONSTANT)
        Q_PROPERTY(QString fa_sort_down READ get_fa_sort_down CONSTANT)
        Q_PROPERTY(QString fa_sort_numeric_down READ get_fa_sort_numeric_down CONSTANT)
        Q_PROPERTY(QString fa_sort_numeric_down_alt READ get_fa_sort_numeric_down_alt CONSTANT)
        Q_PROPERTY(QString fa_sort_numeric_up READ get_fa_sort_numeric_up CONSTANT)
        Q_PROPERTY(QString fa_sort_numeric_up_alt READ get_fa_sort_numeric_up_alt CONSTANT)
        Q_PROPERTY(QString fa_sort_up READ get_fa_sort_up CONSTANT)
        Q_PROPERTY(QString fa_soundcloud READ get_fa_soundcloud CONSTANT)
        Q_PROPERTY(QString fa_sourcetree READ get_fa_sourcetree CONSTANT)
        Q_PROPERTY(QString fa_spa READ get_fa_spa CONSTANT)
        Q_PROPERTY(QString fa_space_shuttle READ get_fa_space_shuttle CONSTANT)
        Q_PROPERTY(QString fa_speakap READ get_fa_speakap CONSTANT)
        Q_PROPERTY(QString fa_speaker_deck READ get_fa_speaker_deck CONSTANT)
        Q_PROPERTY(QString fa_spell_check READ get_fa_spell_check CONSTANT)
        Q_PROPERTY(QString fa_spider READ get_fa_spider CONSTANT)
        Q_PROPERTY(QString fa_spinner READ get_fa_spinner CONSTANT)
        Q_PROPERTY(QString fa_splotch READ get_fa_splotch CONSTANT)
        Q_PROPERTY(QString fa_spotify READ get_fa_spotify CONSTANT)
        Q_PROPERTY(QString fa_spray_can READ get_fa_spray_can CONSTANT)
        Q_PROPERTY(QString fa_square READ get_fa_square CONSTANT)
        Q_PROPERTY(QString fa_square_full READ get_fa_square_full CONSTANT)
        Q_PROPERTY(QString fa_square_root_alt READ get_fa_square_root_alt CONSTANT)
        Q_PROPERTY(QString fa_squarespace READ get_fa_squarespace CONSTANT)
        Q_PROPERTY(QString fa_stack_exchange READ get_fa_stack_exchange CONSTANT)
        Q_PROPERTY(QString fa_stack_overflow READ get_fa_stack_overflow CONSTANT)
        Q_PROPERTY(QString fa_stackpath READ get_fa_stackpath CONSTANT)
        Q_PROPERTY(QString fa_stamp READ get_fa_stamp CONSTANT)
        Q_PROPERTY(QString fa_star READ get_fa_star CONSTANT)
        Q_PROPERTY(QString fa_star_and_crescent READ get_fa_star_and_crescent CONSTANT)
        Q_PROPERTY(QString fa_star_half READ get_fa_star_half CONSTANT)
        Q_PROPERTY(QString fa_star_half_alt READ get_fa_star_half_alt CONSTANT)
        Q_PROPERTY(QString fa_star_of_david READ get_fa_star_of_david CONSTANT)
        Q_PROPERTY(QString fa_star_of_life READ get_fa_star_of_life CONSTANT)
        Q_PROPERTY(QString fa_staylinked READ get_fa_staylinked CONSTANT)
        Q_PROPERTY(QString fa_steam READ get_fa_steam CONSTANT)
        Q_PROPERTY(QString fa_steam_square READ get_fa_steam_square CONSTANT)
        Q_PROPERTY(QString fa_steam_symbol READ get_fa_steam_symbol CONSTANT)
        Q_PROPERTY(QString fa_step_backward READ get_fa_step_backward CONSTANT)
        Q_PROPERTY(QString fa_step_forward READ get_fa_step_forward CONSTANT)
        Q_PROPERTY(QString fa_stethoscope READ get_fa_stethoscope CONSTANT)
        Q_PROPERTY(QString fa_sticker_mule READ get_fa_sticker_mule CONSTANT)
        Q_PROPERTY(QString fa_sticky_note READ get_fa_sticky_note CONSTANT)
        Q_PROPERTY(QString fa_stop READ get_fa_stop CONSTANT)
        Q_PROPERTY(QString fa_stop_circle READ get_fa_stop_circle CONSTANT)
        Q_PROPERTY(QString fa_stopwatch READ get_fa_stopwatch CONSTANT)
        Q_PROPERTY(QString fa_store READ get_fa_store CONSTANT)
        Q_PROPERTY(QString fa_store_alt READ get_fa_store_alt CONSTANT)
        Q_PROPERTY(QString fa_strava READ get_fa_strava CONSTANT)
        Q_PROPERTY(QString fa_stream READ get_fa_stream CONSTANT)
        Q_PROPERTY(QString fa_street_view READ get_fa_street_view CONSTANT)
        Q_PROPERTY(QString fa_strikethrough READ get_fa_strikethrough CONSTANT)
        Q_PROPERTY(QString fa_stripe READ get_fa_stripe CONSTANT)
        Q_PROPERTY(QString fa_stripe_s READ get_fa_stripe_s CONSTANT)
        Q_PROPERTY(QString fa_stroopwafel READ get_fa_stroopwafel CONSTANT)
        Q_PROPERTY(QString fa_studiovinari READ get_fa_studiovinari CONSTANT)
        Q_PROPERTY(QString fa_stumbleupon READ get_fa_stumbleupon CONSTANT)
        Q_PROPERTY(QString fa_stumbleupon_circle READ get_fa_stumbleupon_circle CONSTANT)
        Q_PROPERTY(QString fa_subscript READ get_fa_subscript CONSTANT)
        Q_PROPERTY(QString fa_subway READ get_fa_subway CONSTANT)
        Q_PROPERTY(QString fa_suitcase READ get_fa_suitcase CONSTANT)
        Q_PROPERTY(QString fa_suitcase_rolling READ get_fa_suitcase_rolling CONSTANT)
        Q_PROPERTY(QString fa_sun READ get_fa_sun CONSTANT)
        Q_PROPERTY(QString fa_superpowers READ get_fa_superpowers CONSTANT)
        Q_PROPERTY(QString fa_superscript READ get_fa_superscript CONSTANT)
        Q_PROPERTY(QString fa_supple READ get_fa_supple CONSTANT)
        Q_PROPERTY(QString fa_surprise READ get_fa_surprise CONSTANT)
        Q_PROPERTY(QString fa_suse READ get_fa_suse CONSTANT)
        Q_PROPERTY(QString fa_swatchbook READ get_fa_swatchbook CONSTANT)
        Q_PROPERTY(QString fa_swift READ get_fa_swift CONSTANT)
        Q_PROPERTY(QString fa_swimmer READ get_fa_swimmer CONSTANT)
        Q_PROPERTY(QString fa_swimming_pool READ get_fa_swimming_pool CONSTANT)
        Q_PROPERTY(QString fa_symfony READ get_fa_symfony CONSTANT)
        Q_PROPERTY(QString fa_synagogue READ get_fa_synagogue CONSTANT)
        Q_PROPERTY(QString fa_sync READ get_fa_sync CONSTANT)
        Q_PROPERTY(QString fa_sync_alt READ get_fa_sync_alt CONSTANT)
        Q_PROPERTY(QString fa_syringe READ get_fa_syringe CONSTANT)
        Q_PROPERTY(QString fa_table READ get_fa_table CONSTANT)
        Q_PROPERTY(QString fa_table_tennis READ get_fa_table_tennis CONSTANT)
        Q_PROPERTY(QString fa_tablet READ get_fa_tablet CONSTANT)
        Q_PROPERTY(QString fa_tablet_alt READ get_fa_tablet_alt CONSTANT)
        Q_PROPERTY(QString fa_tablets READ get_fa_tablets CONSTANT)
        Q_PROPERTY(QString fa_tachometer_alt READ get_fa_tachometer_alt CONSTANT)
        Q_PROPERTY(QString fa_tag READ get_fa_tag CONSTANT)
        Q_PROPERTY(QString fa_tags READ get_fa_tags CONSTANT)
        Q_PROPERTY(QString fa_tape READ get_fa_tape CONSTANT)
        Q_PROPERTY(QString fa_tasks READ get_fa_tasks CONSTANT)
        Q_PROPERTY(QString fa_taxi READ get_fa_taxi CONSTANT)
        Q_PROPERTY(QString fa_teamspeak READ get_fa_teamspeak CONSTANT)
        Q_PROPERTY(QString fa_teeth READ get_fa_teeth CONSTANT)
        Q_PROPERTY(QString fa_teeth_open READ get_fa_teeth_open CONSTANT)
        Q_PROPERTY(QString fa_telegram READ get_fa_telegram CONSTANT)
        Q_PROPERTY(QString fa_telegram_plane READ get_fa_telegram_plane CONSTANT)
        Q_PROPERTY(QString fa_temperature_high READ get_fa_temperature_high CONSTANT)
        Q_PROPERTY(QString fa_temperature_low READ get_fa_temperature_low CONSTANT)
        Q_PROPERTY(QString fa_tencent_weibo READ get_fa_tencent_weibo CONSTANT)
        Q_PROPERTY(QString fa_tenge READ get_fa_tenge CONSTANT)
        Q_PROPERTY(QString fa_terminal READ get_fa_terminal CONSTANT)
        Q_PROPERTY(QString fa_text_height READ get_fa_text_height CONSTANT)
        Q_PROPERTY(QString fa_text_width READ get_fa_text_width CONSTANT)
        Q_PROPERTY(QString fa_th READ get_fa_th CONSTANT)
        Q_PROPERTY(QString fa_th_large READ get_fa_th_large CONSTANT)
        Q_PROPERTY(QString fa_th_list READ get_fa_th_list CONSTANT)
        Q_PROPERTY(QString fa_the_red_yeti READ get_fa_the_red_yeti CONSTANT)
        Q_PROPERTY(QString fa_theater_masks READ get_fa_theater_masks CONSTANT)
        Q_PROPERTY(QString fa_themeco READ get_fa_themeco CONSTANT)
        Q_PROPERTY(QString fa_themeisle READ get_fa_themeisle CONSTANT)
        Q_PROPERTY(QString fa_thermometer READ get_fa_thermometer CONSTANT)
        Q_PROPERTY(QString fa_thermometer_empty READ get_fa_thermometer_empty CONSTANT)
        Q_PROPERTY(QString fa_thermometer_full READ get_fa_thermometer_full CONSTANT)
        Q_PROPERTY(QString fa_thermometer_half READ get_fa_thermometer_half CONSTANT)
        Q_PROPERTY(QString fa_thermometer_quarter READ get_fa_thermometer_quarter CONSTANT)
        Q_PROPERTY(QString fa_thermometer_three_quarters READ get_fa_thermometer_three_quarters CONSTANT)
        Q_PROPERTY(QString fa_think_peaks READ get_fa_think_peaks CONSTANT)
        Q_PROPERTY(QString fa_thumbs_down READ get_fa_thumbs_down CONSTANT)
        Q_PROPERTY(QString fa_thumbs_up READ get_fa_thumbs_up CONSTANT)
        Q_PROPERTY(QString fa_thumbtack READ get_fa_thumbtack CONSTANT)
        Q_PROPERTY(QString fa_ticket_alt READ get_fa_ticket_alt CONSTANT)
        Q_PROPERTY(QString fa_times READ get_fa_times CONSTANT)
        Q_PROPERTY(QString fa_times_circle READ get_fa_times_circle CONSTANT)
        Q_PROPERTY(QString fa_tint READ get_fa_tint CONSTANT)
        Q_PROPERTY(QString fa_tint_slash READ get_fa_tint_slash CONSTANT)
        Q_PROPERTY(QString fa_tired READ get_fa_tired CONSTANT)
        Q_PROPERTY(QString fa_toggle_off READ get_fa_toggle_off CONSTANT)
        Q_PROPERTY(QString fa_toggle_on READ get_fa_toggle_on CONSTANT)
        Q_PROPERTY(QString fa_toilet READ get_fa_toilet CONSTANT)
        Q_PROPERTY(QString fa_toilet_paper READ get_fa_toilet_paper CONSTANT)
        Q_PROPERTY(QString fa_toolbox READ get_fa_toolbox CONSTANT)
        Q_PROPERTY(QString fa_tools READ get_fa_tools CONSTANT)
        Q_PROPERTY(QString fa_tooth READ get_fa_tooth CONSTANT)
        Q_PROPERTY(QString fa_torah READ get_fa_torah CONSTANT)
        Q_PROPERTY(QString fa_torii_gate READ get_fa_torii_gate CONSTANT)
        Q_PROPERTY(QString fa_tractor READ get_fa_tractor CONSTANT)
        Q_PROPERTY(QString fa_trade_federation READ get_fa_trade_federation CONSTANT)
        Q_PROPERTY(QString fa_trademark READ get_fa_trademark CONSTANT)
        Q_PROPERTY(QString fa_traffic_light READ get_fa_traffic_light CONSTANT)
        Q_PROPERTY(QString fa_train READ get_fa_train CONSTANT)
        Q_PROPERTY(QString fa_tram READ get_fa_tram CONSTANT)
        Q_PROPERTY(QString fa_transgender READ get_fa_transgender CONSTANT)
        Q_PROPERTY(QString fa_transgender_alt READ get_fa_transgender_alt CONSTANT)
        Q_PROPERTY(QString fa_trash READ get_fa_trash CONSTANT)
        Q_PROPERTY(QString fa_trash_alt READ get_fa_trash_alt CONSTANT)
        Q_PROPERTY(QString fa_trash_restore READ get_fa_trash_restore CONSTANT)
        Q_PROPERTY(QString fa_trash_restore_alt READ get_fa_trash_restore_alt CONSTANT)
        Q_PROPERTY(QString fa_tree READ get_fa_tree CONSTANT)
        Q_PROPERTY(QString fa_trello READ get_fa_trello CONSTANT)
        Q_PROPERTY(QString fa_tripadvisor READ get_fa_tripadvisor CONSTANT)
        Q_PROPERTY(QString fa_trophy READ get_fa_trophy CONSTANT)
        Q_PROPERTY(QString fa_truck READ get_fa_truck CONSTANT)
        Q_PROPERTY(QString fa_truck_loading READ get_fa_truck_loading CONSTANT)
        Q_PROPERTY(QString fa_truck_monster READ get_fa_truck_monster CONSTANT)
        Q_PROPERTY(QString fa_truck_moving READ get_fa_truck_moving CONSTANT)
        Q_PROPERTY(QString fa_truck_pickup READ get_fa_truck_pickup CONSTANT)
        Q_PROPERTY(QString fa_tshirt READ get_fa_tshirt CONSTANT)
        Q_PROPERTY(QString fa_tty READ get_fa_tty CONSTANT)
        Q_PROPERTY(QString fa_tumblr READ get_fa_tumblr CONSTANT)
        Q_PROPERTY(QString fa_tumblr_square READ get_fa_tumblr_square CONSTANT)
        Q_PROPERTY(QString fa_tv READ get_fa_tv CONSTANT)
        Q_PROPERTY(QString fa_twitch READ get_fa_twitch CONSTANT)
        Q_PROPERTY(QString fa_twitter READ get_fa_twitter CONSTANT)
        Q_PROPERTY(QString fa_twitter_square READ get_fa_twitter_square CONSTANT)
        Q_PROPERTY(QString fa_typo3 READ get_fa_typo3 CONSTANT)
        Q_PROPERTY(QString fa_uber READ get_fa_uber CONSTANT)
        Q_PROPERTY(QString fa_ubuntu READ get_fa_ubuntu CONSTANT)
        Q_PROPERTY(QString fa_uikit READ get_fa_uikit CONSTANT)
        Q_PROPERTY(QString fa_umbraco READ get_fa_umbraco CONSTANT)
        Q_PROPERTY(QString fa_umbrella READ get_fa_umbrella CONSTANT)
        Q_PROPERTY(QString fa_umbrella_beach READ get_fa_umbrella_beach CONSTANT)
        Q_PROPERTY(QString fa_underline READ get_fa_underline CONSTANT)
        Q_PROPERTY(QString fa_undo READ get_fa_undo CONSTANT)
        Q_PROPERTY(QString fa_undo_alt READ get_fa_undo_alt CONSTANT)
        Q_PROPERTY(QString fa_uniregistry READ get_fa_uniregistry CONSTANT)
        Q_PROPERTY(QString fa_universal_access READ get_fa_universal_access CONSTANT)
        Q_PROPERTY(QString fa_university READ get_fa_university CONSTANT)
        Q_PROPERTY(QString fa_unlink READ get_fa_unlink CONSTANT)
        Q_PROPERTY(QString fa_unlock READ get_fa_unlock CONSTANT)
        Q_PROPERTY(QString fa_unlock_alt READ get_fa_unlock_alt CONSTANT)
        Q_PROPERTY(QString fa_untappd READ get_fa_untappd CONSTANT)
        Q_PROPERTY(QString fa_upload READ get_fa_upload CONSTANT)
        Q_PROPERTY(QString fa_ups READ get_fa_ups CONSTANT)
        Q_PROPERTY(QString fa_usb READ get_fa_usb CONSTANT)
        Q_PROPERTY(QString fa_user READ get_fa_user CONSTANT)
        Q_PROPERTY(QString fa_user_alt READ get_fa_user_alt CONSTANT)
        Q_PROPERTY(QString fa_user_alt_slash READ get_fa_user_alt_slash CONSTANT)
        Q_PROPERTY(QString fa_user_astronaut READ get_fa_user_astronaut CONSTANT)
        Q_PROPERTY(QString fa_user_check READ get_fa_user_check CONSTANT)
        Q_PROPERTY(QString fa_user_circle READ get_fa_user_circle CONSTANT)
        Q_PROPERTY(QString fa_user_clock READ get_fa_user_clock CONSTANT)
        Q_PROPERTY(QString fa_user_cog READ get_fa_user_cog CONSTANT)
        Q_PROPERTY(QString fa_user_edit READ get_fa_user_edit CONSTANT)
        Q_PROPERTY(QString fa_user_friends READ get_fa_user_friends CONSTANT)
        Q_PROPERTY(QString fa_user_graduate READ get_fa_user_graduate CONSTANT)
        Q_PROPERTY(QString fa_user_injured READ get_fa_user_injured CONSTANT)
        Q_PROPERTY(QString fa_user_lock READ get_fa_user_lock CONSTANT)
        Q_PROPERTY(QString fa_user_md READ get_fa_user_md CONSTANT)
        Q_PROPERTY(QString fa_user_minus READ get_fa_user_minus CONSTANT)
        Q_PROPERTY(QString fa_user_ninja READ get_fa_user_ninja CONSTANT)
        Q_PROPERTY(QString fa_user_nurse READ get_fa_user_nurse CONSTANT)
        Q_PROPERTY(QString fa_user_plus READ get_fa_user_plus CONSTANT)
        Q_PROPERTY(QString fa_user_secret READ get_fa_user_secret CONSTANT)
        Q_PROPERTY(QString fa_user_shield READ get_fa_user_shield CONSTANT)
        Q_PROPERTY(QString fa_user_slash READ get_fa_user_slash CONSTANT)
        Q_PROPERTY(QString fa_user_tag READ get_fa_user_tag CONSTANT)
        Q_PROPERTY(QString fa_user_tie READ get_fa_user_tie CONSTANT)
        Q_PROPERTY(QString fa_user_times READ get_fa_user_times CONSTANT)
        Q_PROPERTY(QString fa_users READ get_fa_users CONSTANT)
        Q_PROPERTY(QString fa_users_cog READ get_fa_users_cog CONSTANT)
        Q_PROPERTY(QString fa_usps READ get_fa_usps CONSTANT)
        Q_PROPERTY(QString fa_ussunnah READ get_fa_ussunnah CONSTANT)
        Q_PROPERTY(QString fa_utensil_spoon READ get_fa_utensil_spoon CONSTANT)
        Q_PROPERTY(QString fa_utensils READ get_fa_utensils CONSTANT)
        Q_PROPERTY(QString fa_vaadin READ get_fa_vaadin CONSTANT)
        Q_PROPERTY(QString fa_vector_square READ get_fa_vector_square CONSTANT)
        Q_PROPERTY(QString fa_venus READ get_fa_venus CONSTANT)
        Q_PROPERTY(QString fa_venus_double READ get_fa_venus_double CONSTANT)
        Q_PROPERTY(QString fa_venus_mars READ get_fa_venus_mars CONSTANT)
        Q_PROPERTY(QString fa_viacoin READ get_fa_viacoin CONSTANT)
        Q_PROPERTY(QString fa_viadeo READ get_fa_viadeo CONSTANT)
        Q_PROPERTY(QString fa_viadeo_square READ get_fa_viadeo_square CONSTANT)
        Q_PROPERTY(QString fa_vial READ get_fa_vial CONSTANT)
        Q_PROPERTY(QString fa_vials READ get_fa_vials CONSTANT)
        Q_PROPERTY(QString fa_viber READ get_fa_viber CONSTANT)
        Q_PROPERTY(QString fa_video READ get_fa_video CONSTANT)
        Q_PROPERTY(QString fa_video_slash READ get_fa_video_slash CONSTANT)
        Q_PROPERTY(QString fa_vihara READ get_fa_vihara CONSTANT)
        Q_PROPERTY(QString fa_vimeo READ get_fa_vimeo CONSTANT)
        Q_PROPERTY(QString fa_vimeo_square READ get_fa_vimeo_square CONSTANT)
        Q_PROPERTY(QString fa_vimeo_v READ get_fa_vimeo_v CONSTANT)
        Q_PROPERTY(QString fa_vine READ get_fa_vine CONSTANT)
        Q_PROPERTY(QString fa_vk READ get_fa_vk CONSTANT)
        Q_PROPERTY(QString fa_vnv READ get_fa_vnv CONSTANT)
        Q_PROPERTY(QString fa_voicemail READ get_fa_voicemail CONSTANT)
        Q_PROPERTY(QString fa_volleyball_ball READ get_fa_volleyball_ball CONSTANT)
        Q_PROPERTY(QString fa_volume_down READ get_fa_volume_down CONSTANT)
        Q_PROPERTY(QString fa_volume_mute READ get_fa_volume_mute CONSTANT)
        Q_PROPERTY(QString fa_volume_off READ get_fa_volume_off CONSTANT)
        Q_PROPERTY(QString fa_volume_up READ get_fa_volume_up CONSTANT)
        Q_PROPERTY(QString fa_vote_yea READ get_fa_vote_yea CONSTANT)
        Q_PROPERTY(QString fa_vr_cardboard READ get_fa_vr_cardboard CONSTANT)
        Q_PROPERTY(QString fa_vuejs READ get_fa_vuejs CONSTANT)
        Q_PROPERTY(QString fa_walking READ get_fa_walking CONSTANT)
        Q_PROPERTY(QString fa_wallet READ get_fa_wallet CONSTANT)
        Q_PROPERTY(QString fa_warehouse READ get_fa_warehouse CONSTANT)
        Q_PROPERTY(QString fa_water READ get_fa_water CONSTANT)
        Q_PROPERTY(QString fa_wave_square READ get_fa_wave_square CONSTANT)
        Q_PROPERTY(QString fa_waze READ get_fa_waze CONSTANT)
        Q_PROPERTY(QString fa_weebly READ get_fa_weebly CONSTANT)
        Q_PROPERTY(QString fa_weibo READ get_fa_weibo CONSTANT)
        Q_PROPERTY(QString fa_weight READ get_fa_weight CONSTANT)
        Q_PROPERTY(QString fa_weight_hanging READ get_fa_weight_hanging CONSTANT)
        Q_PROPERTY(QString fa_weixin READ get_fa_weixin CONSTANT)
        Q_PROPERTY(QString fa_whatsapp READ get_fa_whatsapp CONSTANT)
        Q_PROPERTY(QString fa_whatsapp_square READ get_fa_whatsapp_square CONSTANT)
        Q_PROPERTY(QString fa_wheelchair READ get_fa_wheelchair CONSTANT)
        Q_PROPERTY(QString fa_whmcs READ get_fa_whmcs CONSTANT)
        Q_PROPERTY(QString fa_wifi READ get_fa_wifi CONSTANT)
        Q_PROPERTY(QString fa_wikipedia_w READ get_fa_wikipedia_w CONSTANT)
        Q_PROPERTY(QString fa_wind READ get_fa_wind CONSTANT)
        Q_PROPERTY(QString fa_window_close READ get_fa_window_close CONSTANT)
        Q_PROPERTY(QString fa_window_maximize READ get_fa_window_maximize CONSTANT)
        Q_PROPERTY(QString fa_window_minimize READ get_fa_window_minimize CONSTANT)
        Q_PROPERTY(QString fa_window_restore READ get_fa_window_restore CONSTANT)
        Q_PROPERTY(QString fa_windows READ get_fa_windows CONSTANT)
        Q_PROPERTY(QString fa_wine_bottle READ get_fa_wine_bottle CONSTANT)
        Q_PROPERTY(QString fa_wine_glass READ get_fa_wine_glass CONSTANT)
        Q_PROPERTY(QString fa_wine_glass_alt READ get_fa_wine_glass_alt CONSTANT)
        Q_PROPERTY(QString fa_wix READ get_fa_wix CONSTANT)
        Q_PROPERTY(QString fa_wizards_of_the_coast READ get_fa_wizards_of_the_coast CONSTANT)
        Q_PROPERTY(QString fa_wolf_pack_battalion READ get_fa_wolf_pack_battalion CONSTANT)
        Q_PROPERTY(QString fa_won_sign READ get_fa_won_sign CONSTANT)
        Q_PROPERTY(QString fa_wordpress READ get_fa_wordpress CONSTANT)
        Q_PROPERTY(QString fa_wordpress_simple READ get_fa_wordpress_simple CONSTANT)
        Q_PROPERTY(QString fa_wpbeginner READ get_fa_wpbeginner CONSTANT)
        Q_PROPERTY(QString fa_wpexplorer READ get_fa_wpexplorer CONSTANT)
        Q_PROPERTY(QString fa_wpforms READ get_fa_wpforms CONSTANT)
        Q_PROPERTY(QString fa_wpressr READ get_fa_wpressr CONSTANT)
        Q_PROPERTY(QString fa_wrench READ get_fa_wrench CONSTANT)
        Q_PROPERTY(QString fa_x_ray READ get_fa_x_ray CONSTANT)
        Q_PROPERTY(QString fa_xbox READ get_fa_xbox CONSTANT)
        Q_PROPERTY(QString fa_xing READ get_fa_xing CONSTANT)
        Q_PROPERTY(QString fa_xing_square READ get_fa_xing_square CONSTANT)
        Q_PROPERTY(QString fa_y_combinator READ get_fa_y_combinator CONSTANT)
        Q_PROPERTY(QString fa_yahoo READ get_fa_yahoo CONSTANT)
        Q_PROPERTY(QString fa_yammer READ get_fa_yammer CONSTANT)
        Q_PROPERTY(QString fa_yandex READ get_fa_yandex CONSTANT)
        Q_PROPERTY(QString fa_yandex_international READ get_fa_yandex_international CONSTANT)
        Q_PROPERTY(QString fa_yarn READ get_fa_yarn CONSTANT)
        Q_PROPERTY(QString fa_yelp READ get_fa_yelp CONSTANT)
        Q_PROPERTY(QString fa_yen_sign READ get_fa_yen_sign CONSTANT)
        Q_PROPERTY(QString fa_yin_yang READ get_fa_yin_yang CONSTANT)
        Q_PROPERTY(QString fa_yoast READ get_fa_yoast CONSTANT)
        Q_PROPERTY(QString fa_youtube READ get_fa_youtube CONSTANT)
        Q_PROPERTY(QString fa_youtube_square READ get_fa_youtube_square CONSTANT)
        Q_PROPERTY(QString fa_zhihu READ get_fa_zhihu CONSTANT)
        const QString& get_fa_500px() const {return fa_500px;}
        const QString& get_fa_accessible_icon() const {return fa_accessible_icon;}
        const QString& get_fa_accusoft() const {return fa_accusoft;}
        const QString& get_fa_acquisitions_incorporated() const {return fa_acquisitions_incorporated;}
        const QString& get_fa_ad() const {return fa_ad;}
        const QString& get_fa_address_book() const {return fa_address_book;}
        const QString& get_fa_address_card() const {return fa_address_card;}
        const QString& get_fa_adjust() const {return fa_adjust;}
        const QString& get_fa_adn() const {return fa_adn;}
        const QString& get_fa_adobe() const {return fa_adobe;}
        const QString& get_fa_adversal() const {return fa_adversal;}
        const QString& get_fa_affiliatetheme() const {return fa_affiliatetheme;}
        const QString& get_fa_air_freshener() const {return fa_air_freshener;}
        const QString& get_fa_airbnb() const {return fa_airbnb;}
        const QString& get_fa_algolia() const {return fa_algolia;}
        const QString& get_fa_align_center() const {return fa_align_center;}
        const QString& get_fa_align_justify() const {return fa_align_justify;}
        const QString& get_fa_align_left() const {return fa_align_left;}
        const QString& get_fa_align_right() const {return fa_align_right;}
        const QString& get_fa_alipay() const {return fa_alipay;}
        const QString& get_fa_allergies() const {return fa_allergies;}
        const QString& get_fa_amazon() const {return fa_amazon;}
        const QString& get_fa_amazon_pay() const {return fa_amazon_pay;}
        const QString& get_fa_ambulance() const {return fa_ambulance;}
        const QString& get_fa_american_sign_language_interpreting() const {return fa_american_sign_language_interpreting;}
        const QString& get_fa_amilia() const {return fa_amilia;}
        const QString& get_fa_anchor() const {return fa_anchor;}
        const QString& get_fa_android() const {return fa_android;}
        const QString& get_fa_angellist() const {return fa_angellist;}
        const QString& get_fa_angle_double_down() const {return fa_angle_double_down;}
        const QString& get_fa_angle_double_left() const {return fa_angle_double_left;}
        const QString& get_fa_angle_double_right() const {return fa_angle_double_right;}
        const QString& get_fa_angle_double_up() const {return fa_angle_double_up;}
        const QString& get_fa_angle_down() const {return fa_angle_down;}
        const QString& get_fa_angle_left() const {return fa_angle_left;}
        const QString& get_fa_angle_right() const {return fa_angle_right;}
        const QString& get_fa_angle_up() const {return fa_angle_up;}
        const QString& get_fa_angry() const {return fa_angry;}
        const QString& get_fa_angrycreative() const {return fa_angrycreative;}
        const QString& get_fa_angular() const {return fa_angular;}
        const QString& get_fa_ankh() const {return fa_ankh;}
        const QString& get_fa_app_store() const {return fa_app_store;}
        const QString& get_fa_app_store_ios() const {return fa_app_store_ios;}
        const QString& get_fa_apper() const {return fa_apper;}
        const QString& get_fa_apple() const {return fa_apple;}
        const QString& get_fa_apple_alt() const {return fa_apple_alt;}
        const QString& get_fa_apple_pay() const {return fa_apple_pay;}
        const QString& get_fa_archive() const {return fa_archive;}
        const QString& get_fa_archway() const {return fa_archway;}
        const QString& get_fa_arrow_alt_circle_down() const {return fa_arrow_alt_circle_down;}
        const QString& get_fa_arrow_alt_circle_left() const {return fa_arrow_alt_circle_left;}
        const QString& get_fa_arrow_alt_circle_right() const {return fa_arrow_alt_circle_right;}
        const QString& get_fa_arrow_alt_circle_up() const {return fa_arrow_alt_circle_up;}
        const QString& get_fa_arrow_circle_down() const {return fa_arrow_circle_down;}
        const QString& get_fa_arrow_circle_left() const {return fa_arrow_circle_left;}
        const QString& get_fa_arrow_circle_right() const {return fa_arrow_circle_right;}
        const QString& get_fa_arrow_circle_up() const {return fa_arrow_circle_up;}
        const QString& get_fa_arrow_down() const {return fa_arrow_down;}
        const QString& get_fa_arrow_left() const {return fa_arrow_left;}
        const QString& get_fa_arrow_right() const {return fa_arrow_right;}
        const QString& get_fa_arrow_up() const {return fa_arrow_up;}
        const QString& get_fa_arrows_alt() const {return fa_arrows_alt;}
        const QString& get_fa_arrows_alt_h() const {return fa_arrows_alt_h;}
        const QString& get_fa_arrows_alt_v() const {return fa_arrows_alt_v;}
        const QString& get_fa_artstation() const {return fa_artstation;}
        const QString& get_fa_assistive_listening_systems() const {return fa_assistive_listening_systems;}
        const QString& get_fa_asterisk() const {return fa_asterisk;}
        const QString& get_fa_asymmetrik() const {return fa_asymmetrik;}
        const QString& get_fa_at() const {return fa_at;}
        const QString& get_fa_atlas() const {return fa_atlas;}
        const QString& get_fa_atlassian() const {return fa_atlassian;}
        const QString& get_fa_atom() const {return fa_atom;}
        const QString& get_fa_audible() const {return fa_audible;}
        const QString& get_fa_audio_description() const {return fa_audio_description;}
        const QString& get_fa_autoprefixer() const {return fa_autoprefixer;}
        const QString& get_fa_avianex() const {return fa_avianex;}
        const QString& get_fa_aviato() const {return fa_aviato;}
        const QString& get_fa_award() const {return fa_award;}
        const QString& get_fa_aws() const {return fa_aws;}
        const QString& get_fa_baby() const {return fa_baby;}
        const QString& get_fa_baby_carriage() const {return fa_baby_carriage;}
        const QString& get_fa_backspace() const {return fa_backspace;}
        const QString& get_fa_backward() const {return fa_backward;}
        const QString& get_fa_bacon() const {return fa_bacon;}
        const QString& get_fa_balance_scale() const {return fa_balance_scale;}
        const QString& get_fa_balance_scale_left() const {return fa_balance_scale_left;}
        const QString& get_fa_balance_scale_right() const {return fa_balance_scale_right;}
        const QString& get_fa_ban() const {return fa_ban;}
        const QString& get_fa_band_aid() const {return fa_band_aid;}
        const QString& get_fa_bandcamp() const {return fa_bandcamp;}
        const QString& get_fa_barcode() const {return fa_barcode;}
        const QString& get_fa_bars() const {return fa_bars;}
        const QString& get_fa_baseball_ball() const {return fa_baseball_ball;}
        const QString& get_fa_basketball_ball() const {return fa_basketball_ball;}
        const QString& get_fa_bath() const {return fa_bath;}
        const QString& get_fa_battery_empty() const {return fa_battery_empty;}
        const QString& get_fa_battery_full() const {return fa_battery_full;}
        const QString& get_fa_battery_half() const {return fa_battery_half;}
        const QString& get_fa_battery_quarter() const {return fa_battery_quarter;}
        const QString& get_fa_battery_three_quarters() const {return fa_battery_three_quarters;}
        const QString& get_fa_battle_net() const {return fa_battle_net;}
        const QString& get_fa_bed() const {return fa_bed;}
        const QString& get_fa_beer() const {return fa_beer;}
        const QString& get_fa_behance() const {return fa_behance;}
        const QString& get_fa_behance_square() const {return fa_behance_square;}
        const QString& get_fa_bell() const {return fa_bell;}
        const QString& get_fa_bell_slash() const {return fa_bell_slash;}
        const QString& get_fa_bezier_curve() const {return fa_bezier_curve;}
        const QString& get_fa_bible() const {return fa_bible;}
        const QString& get_fa_bicycle() const {return fa_bicycle;}
        const QString& get_fa_biking() const {return fa_biking;}
        const QString& get_fa_bimobject() const {return fa_bimobject;}
        const QString& get_fa_binoculars() const {return fa_binoculars;}
        const QString& get_fa_biohazard() const {return fa_biohazard;}
        const QString& get_fa_birthday_cake() const {return fa_birthday_cake;}
        const QString& get_fa_bitbucket() const {return fa_bitbucket;}
        const QString& get_fa_bitcoin() const {return fa_bitcoin;}
        const QString& get_fa_bity() const {return fa_bity;}
        const QString& get_fa_black_tie() const {return fa_black_tie;}
        const QString& get_fa_blackberry() const {return fa_blackberry;}
        const QString& get_fa_blender() const {return fa_blender;}
        const QString& get_fa_blender_phone() const {return fa_blender_phone;}
        const QString& get_fa_blind() const {return fa_blind;}
        const QString& get_fa_blog() const {return fa_blog;}
        const QString& get_fa_blogger() const {return fa_blogger;}
        const QString& get_fa_blogger_b() const {return fa_blogger_b;}
        const QString& get_fa_bluetooth() const {return fa_bluetooth;}
        const QString& get_fa_bluetooth_b() const {return fa_bluetooth_b;}
        const QString& get_fa_bold() const {return fa_bold;}
        const QString& get_fa_bolt() const {return fa_bolt;}
        const QString& get_fa_bomb() const {return fa_bomb;}
        const QString& get_fa_bone() const {return fa_bone;}
        const QString& get_fa_bong() const {return fa_bong;}
        const QString& get_fa_book() const {return fa_book;}
        const QString& get_fa_book_dead() const {return fa_book_dead;}
        const QString& get_fa_book_medical() const {return fa_book_medical;}
        const QString& get_fa_book_open() const {return fa_book_open;}
        const QString& get_fa_book_reader() const {return fa_book_reader;}
        const QString& get_fa_bookmark() const {return fa_bookmark;}
        const QString& get_fa_bootstrap() const {return fa_bootstrap;}
        const QString& get_fa_border_all() const {return fa_border_all;}
        const QString& get_fa_border_none() const {return fa_border_none;}
        const QString& get_fa_border_style() const {return fa_border_style;}
        const QString& get_fa_bowling_ball() const {return fa_bowling_ball;}
        const QString& get_fa_box() const {return fa_box;}
        const QString& get_fa_box_open() const {return fa_box_open;}
        const QString& get_fa_boxes() const {return fa_boxes;}
        const QString& get_fa_braille() const {return fa_braille;}
        const QString& get_fa_brain() const {return fa_brain;}
        const QString& get_fa_bread_slice() const {return fa_bread_slice;}
        const QString& get_fa_briefcase() const {return fa_briefcase;}
        const QString& get_fa_briefcase_medical() const {return fa_briefcase_medical;}
        const QString& get_fa_broadcast_tower() const {return fa_broadcast_tower;}
        const QString& get_fa_broom() const {return fa_broom;}
        const QString& get_fa_brush() const {return fa_brush;}
        const QString& get_fa_btc() const {return fa_btc;}
        const QString& get_fa_buffer() const {return fa_buffer;}
        const QString& get_fa_bug() const {return fa_bug;}
        const QString& get_fa_building() const {return fa_building;}
        const QString& get_fa_bullhorn() const {return fa_bullhorn;}
        const QString& get_fa_bullseye() const {return fa_bullseye;}
        const QString& get_fa_burn() const {return fa_burn;}
        const QString& get_fa_buromobelexperte() const {return fa_buromobelexperte;}
        const QString& get_fa_bus() const {return fa_bus;}
        const QString& get_fa_bus_alt() const {return fa_bus_alt;}
        const QString& get_fa_business_time() const {return fa_business_time;}
        const QString& get_fa_buy_n_large() const {return fa_buy_n_large;}
        const QString& get_fa_buysellads() const {return fa_buysellads;}
        const QString& get_fa_calculator() const {return fa_calculator;}
        const QString& get_fa_calendar() const {return fa_calendar;}
        const QString& get_fa_calendar_alt() const {return fa_calendar_alt;}
        const QString& get_fa_calendar_check() const {return fa_calendar_check;}
        const QString& get_fa_calendar_day() const {return fa_calendar_day;}
        const QString& get_fa_calendar_minus() const {return fa_calendar_minus;}
        const QString& get_fa_calendar_plus() const {return fa_calendar_plus;}
        const QString& get_fa_calendar_times() const {return fa_calendar_times;}
        const QString& get_fa_calendar_week() const {return fa_calendar_week;}
        const QString& get_fa_camera() const {return fa_camera;}
        const QString& get_fa_camera_retro() const {return fa_camera_retro;}
        const QString& get_fa_campground() const {return fa_campground;}
        const QString& get_fa_canadian_maple_leaf() const {return fa_canadian_maple_leaf;}
        const QString& get_fa_candy_cane() const {return fa_candy_cane;}
        const QString& get_fa_cannabis() const {return fa_cannabis;}
        const QString& get_fa_capsules() const {return fa_capsules;}
        const QString& get_fa_car() const {return fa_car;}
        const QString& get_fa_car_alt() const {return fa_car_alt;}
        const QString& get_fa_car_battery() const {return fa_car_battery;}
        const QString& get_fa_car_crash() const {return fa_car_crash;}
        const QString& get_fa_car_side() const {return fa_car_side;}
        const QString& get_fa_caret_down() const {return fa_caret_down;}
        const QString& get_fa_caret_left() const {return fa_caret_left;}
        const QString& get_fa_caret_right() const {return fa_caret_right;}
        const QString& get_fa_caret_square_down() const {return fa_caret_square_down;}
        const QString& get_fa_caret_square_left() const {return fa_caret_square_left;}
        const QString& get_fa_caret_square_right() const {return fa_caret_square_right;}
        const QString& get_fa_caret_square_up() const {return fa_caret_square_up;}
        const QString& get_fa_caret_up() const {return fa_caret_up;}
        const QString& get_fa_carrot() const {return fa_carrot;}
        const QString& get_fa_cart_arrow_down() const {return fa_cart_arrow_down;}
        const QString& get_fa_cart_plus() const {return fa_cart_plus;}
        const QString& get_fa_cash_register() const {return fa_cash_register;}
        const QString& get_fa_cat() const {return fa_cat;}
        const QString& get_fa_cc_amazon_pay() const {return fa_cc_amazon_pay;}
        const QString& get_fa_cc_amex() const {return fa_cc_amex;}
        const QString& get_fa_cc_apple_pay() const {return fa_cc_apple_pay;}
        const QString& get_fa_cc_diners_club() const {return fa_cc_diners_club;}
        const QString& get_fa_cc_discover() const {return fa_cc_discover;}
        const QString& get_fa_cc_jcb() const {return fa_cc_jcb;}
        const QString& get_fa_cc_mastercard() const {return fa_cc_mastercard;}
        const QString& get_fa_cc_paypal() const {return fa_cc_paypal;}
        const QString& get_fa_cc_stripe() const {return fa_cc_stripe;}
        const QString& get_fa_cc_visa() const {return fa_cc_visa;}
        const QString& get_fa_centercode() const {return fa_centercode;}
        const QString& get_fa_centos() const {return fa_centos;}
        const QString& get_fa_certificate() const {return fa_certificate;}
        const QString& get_fa_chair() const {return fa_chair;}
        const QString& get_fa_chalkboard() const {return fa_chalkboard;}
        const QString& get_fa_chalkboard_teacher() const {return fa_chalkboard_teacher;}
        const QString& get_fa_charging_station() const {return fa_charging_station;}
        const QString& get_fa_chart_area() const {return fa_chart_area;}
        const QString& get_fa_chart_bar() const {return fa_chart_bar;}
        const QString& get_fa_chart_line() const {return fa_chart_line;}
        const QString& get_fa_chart_pie() const {return fa_chart_pie;}
        const QString& get_fa_check() const {return fa_check;}
        const QString& get_fa_check_circle() const {return fa_check_circle;}
        const QString& get_fa_check_double() const {return fa_check_double;}
        const QString& get_fa_check_square() const {return fa_check_square;}
        const QString& get_fa_cheese() const {return fa_cheese;}
        const QString& get_fa_chess() const {return fa_chess;}
        const QString& get_fa_chess_bishop() const {return fa_chess_bishop;}
        const QString& get_fa_chess_board() const {return fa_chess_board;}
        const QString& get_fa_chess_king() const {return fa_chess_king;}
        const QString& get_fa_chess_knight() const {return fa_chess_knight;}
        const QString& get_fa_chess_pawn() const {return fa_chess_pawn;}
        const QString& get_fa_chess_queen() const {return fa_chess_queen;}
        const QString& get_fa_chess_rook() const {return fa_chess_rook;}
        const QString& get_fa_chevron_circle_down() const {return fa_chevron_circle_down;}
        const QString& get_fa_chevron_circle_left() const {return fa_chevron_circle_left;}
        const QString& get_fa_chevron_circle_right() const {return fa_chevron_circle_right;}
        const QString& get_fa_chevron_circle_up() const {return fa_chevron_circle_up;}
        const QString& get_fa_chevron_down() const {return fa_chevron_down;}
        const QString& get_fa_chevron_left() const {return fa_chevron_left;}
        const QString& get_fa_chevron_right() const {return fa_chevron_right;}
        const QString& get_fa_chevron_up() const {return fa_chevron_up;}
        const QString& get_fa_child() const {return fa_child;}
        const QString& get_fa_chrome() const {return fa_chrome;}
        const QString& get_fa_chromecast() const {return fa_chromecast;}
        const QString& get_fa_church() const {return fa_church;}
        const QString& get_fa_circle() const {return fa_circle;}
        const QString& get_fa_circle_notch() const {return fa_circle_notch;}
        const QString& get_fa_city() const {return fa_city;}
        const QString& get_fa_clinic_medical() const {return fa_clinic_medical;}
        const QString& get_fa_clipboard() const {return fa_clipboard;}
        const QString& get_fa_clipboard_check() const {return fa_clipboard_check;}
        const QString& get_fa_clipboard_list() const {return fa_clipboard_list;}
        const QString& get_fa_clock() const {return fa_clock;}
        const QString& get_fa_clone() const {return fa_clone;}
        const QString& get_fa_closed_captioning() const {return fa_closed_captioning;}
        const QString& get_fa_cloud() const {return fa_cloud;}
        const QString& get_fa_cloud_download_alt() const {return fa_cloud_download_alt;}
        const QString& get_fa_cloud_meatball() const {return fa_cloud_meatball;}
        const QString& get_fa_cloud_moon() const {return fa_cloud_moon;}
        const QString& get_fa_cloud_moon_rain() const {return fa_cloud_moon_rain;}
        const QString& get_fa_cloud_rain() const {return fa_cloud_rain;}
        const QString& get_fa_cloud_showers_heavy() const {return fa_cloud_showers_heavy;}
        const QString& get_fa_cloud_sun() const {return fa_cloud_sun;}
        const QString& get_fa_cloud_sun_rain() const {return fa_cloud_sun_rain;}
        const QString& get_fa_cloud_upload_alt() const {return fa_cloud_upload_alt;}
        const QString& get_fa_cloudscale() const {return fa_cloudscale;}
        const QString& get_fa_cloudsmith() const {return fa_cloudsmith;}
        const QString& get_fa_cloudversify() const {return fa_cloudversify;}
        const QString& get_fa_cocktail() const {return fa_cocktail;}
        const QString& get_fa_code() const {return fa_code;}
        const QString& get_fa_code_branch() const {return fa_code_branch;}
        const QString& get_fa_codepen() const {return fa_codepen;}
        const QString& get_fa_codiepie() const {return fa_codiepie;}
        const QString& get_fa_coffee() const {return fa_coffee;}
        const QString& get_fa_cog() const {return fa_cog;}
        const QString& get_fa_cogs() const {return fa_cogs;}
        const QString& get_fa_coins() const {return fa_coins;}
        const QString& get_fa_columns() const {return fa_columns;}
        const QString& get_fa_comment() const {return fa_comment;}
        const QString& get_fa_comment_alt() const {return fa_comment_alt;}
        const QString& get_fa_comment_dollar() const {return fa_comment_dollar;}
        const QString& get_fa_comment_dots() const {return fa_comment_dots;}
        const QString& get_fa_comment_medical() const {return fa_comment_medical;}
        const QString& get_fa_comment_slash() const {return fa_comment_slash;}
        const QString& get_fa_comments() const {return fa_comments;}
        const QString& get_fa_comments_dollar() const {return fa_comments_dollar;}
        const QString& get_fa_compact_disc() const {return fa_compact_disc;}
        const QString& get_fa_compass() const {return fa_compass;}
        const QString& get_fa_compress() const {return fa_compress;}
        const QString& get_fa_compress_arrows_alt() const {return fa_compress_arrows_alt;}
        const QString& get_fa_concierge_bell() const {return fa_concierge_bell;}
        const QString& get_fa_confluence() const {return fa_confluence;}
        const QString& get_fa_connectdevelop() const {return fa_connectdevelop;}
        const QString& get_fa_contao() const {return fa_contao;}
        const QString& get_fa_cookie() const {return fa_cookie;}
        const QString& get_fa_cookie_bite() const {return fa_cookie_bite;}
        const QString& get_fa_copy() const {return fa_copy;}
        const QString& get_fa_copyright() const {return fa_copyright;}
        const QString& get_fa_cotton_bureau() const {return fa_cotton_bureau;}
        const QString& get_fa_couch() const {return fa_couch;}
        const QString& get_fa_cpanel() const {return fa_cpanel;}
        const QString& get_fa_creative_commons() const {return fa_creative_commons;}
        const QString& get_fa_creative_commons_by() const {return fa_creative_commons_by;}
        const QString& get_fa_creative_commons_nc() const {return fa_creative_commons_nc;}
        const QString& get_fa_creative_commons_nc_eu() const {return fa_creative_commons_nc_eu;}
        const QString& get_fa_creative_commons_nc_jp() const {return fa_creative_commons_nc_jp;}
        const QString& get_fa_creative_commons_nd() const {return fa_creative_commons_nd;}
        const QString& get_fa_creative_commons_pd() const {return fa_creative_commons_pd;}
        const QString& get_fa_creative_commons_pd_alt() const {return fa_creative_commons_pd_alt;}
        const QString& get_fa_creative_commons_remix() const {return fa_creative_commons_remix;}
        const QString& get_fa_creative_commons_sa() const {return fa_creative_commons_sa;}
        const QString& get_fa_creative_commons_sampling() const {return fa_creative_commons_sampling;}
        const QString& get_fa_creative_commons_sampling_plus() const {return fa_creative_commons_sampling_plus;}
        const QString& get_fa_creative_commons_share() const {return fa_creative_commons_share;}
        const QString& get_fa_creative_commons_zero() const {return fa_creative_commons_zero;}
        const QString& get_fa_credit_card() const {return fa_credit_card;}
        const QString& get_fa_critical_role() const {return fa_critical_role;}
        const QString& get_fa_crop() const {return fa_crop;}
        const QString& get_fa_crop_alt() const {return fa_crop_alt;}
        const QString& get_fa_cross() const {return fa_cross;}
        const QString& get_fa_crosshairs() const {return fa_crosshairs;}
        const QString& get_fa_crow() const {return fa_crow;}
        const QString& get_fa_crown() const {return fa_crown;}
        const QString& get_fa_crutch() const {return fa_crutch;}
        const QString& get_fa_css3() const {return fa_css3;}
        const QString& get_fa_css3_alt() const {return fa_css3_alt;}
        const QString& get_fa_cube() const {return fa_cube;}
        const QString& get_fa_cubes() const {return fa_cubes;}
        const QString& get_fa_cut() const {return fa_cut;}
        const QString& get_fa_cuttlefish() const {return fa_cuttlefish;}
        const QString& get_fa_d_and_d() const {return fa_d_and_d;}
        const QString& get_fa_d_and_d_beyond() const {return fa_d_and_d_beyond;}
        const QString& get_fa_dashcube() const {return fa_dashcube;}
        const QString& get_fa_database() const {return fa_database;}
        const QString& get_fa_deaf() const {return fa_deaf;}
        const QString& get_fa_delicious() const {return fa_delicious;}
        const QString& get_fa_democrat() const {return fa_democrat;}
        const QString& get_fa_deploydog() const {return fa_deploydog;}
        const QString& get_fa_deskpro() const {return fa_deskpro;}
        const QString& get_fa_desktop() const {return fa_desktop;}
        const QString& get_fa_dev() const {return fa_dev;}
        const QString& get_fa_deviantart() const {return fa_deviantart;}
        const QString& get_fa_dharmachakra() const {return fa_dharmachakra;}
        const QString& get_fa_dhl() const {return fa_dhl;}
        const QString& get_fa_diagnoses() const {return fa_diagnoses;}
        const QString& get_fa_diaspora() const {return fa_diaspora;}
        const QString& get_fa_dice() const {return fa_dice;}
        const QString& get_fa_dice_d20() const {return fa_dice_d20;}
        const QString& get_fa_dice_d6() const {return fa_dice_d6;}
        const QString& get_fa_dice_five() const {return fa_dice_five;}
        const QString& get_fa_dice_four() const {return fa_dice_four;}
        const QString& get_fa_dice_one() const {return fa_dice_one;}
        const QString& get_fa_dice_six() const {return fa_dice_six;}
        const QString& get_fa_dice_three() const {return fa_dice_three;}
        const QString& get_fa_dice_two() const {return fa_dice_two;}
        const QString& get_fa_digg() const {return fa_digg;}
        const QString& get_fa_digital_ocean() const {return fa_digital_ocean;}
        const QString& get_fa_digital_tachograph() const {return fa_digital_tachograph;}
        const QString& get_fa_directions() const {return fa_directions;}
        const QString& get_fa_discord() const {return fa_discord;}
        const QString& get_fa_discourse() const {return fa_discourse;}
        const QString& get_fa_divide() const {return fa_divide;}
        const QString& get_fa_dizzy() const {return fa_dizzy;}
        const QString& get_fa_dna() const {return fa_dna;}
        const QString& get_fa_dochub() const {return fa_dochub;}
        const QString& get_fa_docker() const {return fa_docker;}
        const QString& get_fa_dog() const {return fa_dog;}
        const QString& get_fa_dollar_sign() const {return fa_dollar_sign;}
        const QString& get_fa_dolly() const {return fa_dolly;}
        const QString& get_fa_dolly_flatbed() const {return fa_dolly_flatbed;}
        const QString& get_fa_donate() const {return fa_donate;}
        const QString& get_fa_door_closed() const {return fa_door_closed;}
        const QString& get_fa_door_open() const {return fa_door_open;}
        const QString& get_fa_dot_circle() const {return fa_dot_circle;}
        const QString& get_fa_dove() const {return fa_dove;}
        const QString& get_fa_download() const {return fa_download;}
        const QString& get_fa_draft2digital() const {return fa_draft2digital;}
        const QString& get_fa_drafting_compass() const {return fa_drafting_compass;}
        const QString& get_fa_dragon() const {return fa_dragon;}
        const QString& get_fa_draw_polygon() const {return fa_draw_polygon;}
        const QString& get_fa_dribbble() const {return fa_dribbble;}
        const QString& get_fa_dribbble_square() const {return fa_dribbble_square;}
        const QString& get_fa_dropbox() const {return fa_dropbox;}
        const QString& get_fa_drum() const {return fa_drum;}
        const QString& get_fa_drum_steelpan() const {return fa_drum_steelpan;}
        const QString& get_fa_drumstick_bite() const {return fa_drumstick_bite;}
        const QString& get_fa_drupal() const {return fa_drupal;}
        const QString& get_fa_dumbbell() const {return fa_dumbbell;}
        const QString& get_fa_dumpster() const {return fa_dumpster;}
        const QString& get_fa_dumpster_fire() const {return fa_dumpster_fire;}
        const QString& get_fa_dungeon() const {return fa_dungeon;}
        const QString& get_fa_dyalog() const {return fa_dyalog;}
        const QString& get_fa_earlybirds() const {return fa_earlybirds;}
        const QString& get_fa_ebay() const {return fa_ebay;}
        const QString& get_fa_edge() const {return fa_edge;}
        const QString& get_fa_edit() const {return fa_edit;}
        const QString& get_fa_egg() const {return fa_egg;}
        const QString& get_fa_eject() const {return fa_eject;}
        const QString& get_fa_elementor() const {return fa_elementor;}
        const QString& get_fa_ellipsis_h() const {return fa_ellipsis_h;}
        const QString& get_fa_ellipsis_v() const {return fa_ellipsis_v;}
        const QString& get_fa_ello() const {return fa_ello;}
        const QString& get_fa_ember() const {return fa_ember;}
        const QString& get_fa_empire() const {return fa_empire;}
        const QString& get_fa_envelope() const {return fa_envelope;}
        const QString& get_fa_envelope_open() const {return fa_envelope_open;}
        const QString& get_fa_envelope_open_text() const {return fa_envelope_open_text;}
        const QString& get_fa_envelope_square() const {return fa_envelope_square;}
        const QString& get_fa_envira() const {return fa_envira;}
        const QString& get_fa_equals() const {return fa_equals;}
        const QString& get_fa_eraser() const {return fa_eraser;}
        const QString& get_fa_erlang() const {return fa_erlang;}
        const QString& get_fa_ethereum() const {return fa_ethereum;}
        const QString& get_fa_ethernet() const {return fa_ethernet;}
        const QString& get_fa_etsy() const {return fa_etsy;}
        const QString& get_fa_euro_sign() const {return fa_euro_sign;}
        const QString& get_fa_evernote() const {return fa_evernote;}
        const QString& get_fa_exchange_alt() const {return fa_exchange_alt;}
        const QString& get_fa_exclamation() const {return fa_exclamation;}
        const QString& get_fa_exclamation_circle() const {return fa_exclamation_circle;}
        const QString& get_fa_exclamation_triangle() const {return fa_exclamation_triangle;}
        const QString& get_fa_expand() const {return fa_expand;}
        const QString& get_fa_expand_arrows_alt() const {return fa_expand_arrows_alt;}
        const QString& get_fa_expeditedssl() const {return fa_expeditedssl;}
        const QString& get_fa_external_link_alt() const {return fa_external_link_alt;}
        const QString& get_fa_external_link_square_alt() const {return fa_external_link_square_alt;}
        const QString& get_fa_eye() const {return fa_eye;}
        const QString& get_fa_eye_dropper() const {return fa_eye_dropper;}
        const QString& get_fa_eye_slash() const {return fa_eye_slash;}
        const QString& get_fa_facebook() const {return fa_facebook;}
        const QString& get_fa_facebook_f() const {return fa_facebook_f;}
        const QString& get_fa_facebook_messenger() const {return fa_facebook_messenger;}
        const QString& get_fa_facebook_square() const {return fa_facebook_square;}
        const QString& get_fa_fan() const {return fa_fan;}
        const QString& get_fa_fantasy_flight_games() const {return fa_fantasy_flight_games;}
        const QString& get_fa_fast_backward() const {return fa_fast_backward;}
        const QString& get_fa_fast_forward() const {return fa_fast_forward;}
        const QString& get_fa_fax() const {return fa_fax;}
        const QString& get_fa_feather() const {return fa_feather;}
        const QString& get_fa_feather_alt() const {return fa_feather_alt;}
        const QString& get_fa_fedex() const {return fa_fedex;}
        const QString& get_fa_fedora() const {return fa_fedora;}
        const QString& get_fa_female() const {return fa_female;}
        const QString& get_fa_fighter_jet() const {return fa_fighter_jet;}
        const QString& get_fa_figma() const {return fa_figma;}
        const QString& get_fa_file() const {return fa_file;}
        const QString& get_fa_file_alt() const {return fa_file_alt;}
        const QString& get_fa_file_archive() const {return fa_file_archive;}
        const QString& get_fa_file_audio() const {return fa_file_audio;}
        const QString& get_fa_file_code() const {return fa_file_code;}
        const QString& get_fa_file_contract() const {return fa_file_contract;}
        const QString& get_fa_file_csv() const {return fa_file_csv;}
        const QString& get_fa_file_download() const {return fa_file_download;}
        const QString& get_fa_file_excel() const {return fa_file_excel;}
        const QString& get_fa_file_export() const {return fa_file_export;}
        const QString& get_fa_file_image() const {return fa_file_image;}
        const QString& get_fa_file_import() const {return fa_file_import;}
        const QString& get_fa_file_invoice() const {return fa_file_invoice;}
        const QString& get_fa_file_invoice_dollar() const {return fa_file_invoice_dollar;}
        const QString& get_fa_file_medical() const {return fa_file_medical;}
        const QString& get_fa_file_medical_alt() const {return fa_file_medical_alt;}
        const QString& get_fa_file_pdf() const {return fa_file_pdf;}
        const QString& get_fa_file_powerpoint() const {return fa_file_powerpoint;}
        const QString& get_fa_file_prescription() const {return fa_file_prescription;}
        const QString& get_fa_file_signature() const {return fa_file_signature;}
        const QString& get_fa_file_upload() const {return fa_file_upload;}
        const QString& get_fa_file_video() const {return fa_file_video;}
        const QString& get_fa_file_word() const {return fa_file_word;}
        const QString& get_fa_fill() const {return fa_fill;}
        const QString& get_fa_fill_drip() const {return fa_fill_drip;}
        const QString& get_fa_film() const {return fa_film;}
        const QString& get_fa_filter() const {return fa_filter;}
        const QString& get_fa_fingerprint() const {return fa_fingerprint;}
        const QString& get_fa_fire() const {return fa_fire;}
        const QString& get_fa_fire_alt() const {return fa_fire_alt;}
        const QString& get_fa_fire_extinguisher() const {return fa_fire_extinguisher;}
        const QString& get_fa_firefox() const {return fa_firefox;}
        const QString& get_fa_first_aid() const {return fa_first_aid;}
        const QString& get_fa_first_order() const {return fa_first_order;}
        const QString& get_fa_first_order_alt() const {return fa_first_order_alt;}
        const QString& get_fa_firstdraft() const {return fa_firstdraft;}
        const QString& get_fa_fish() const {return fa_fish;}
        const QString& get_fa_fist_raised() const {return fa_fist_raised;}
        const QString& get_fa_flag() const {return fa_flag;}
        const QString& get_fa_flag_checkered() const {return fa_flag_checkered;}
        const QString& get_fa_flag_usa() const {return fa_flag_usa;}
        const QString& get_fa_flask() const {return fa_flask;}
        const QString& get_fa_flickr() const {return fa_flickr;}
        const QString& get_fa_flipboard() const {return fa_flipboard;}
        const QString& get_fa_flushed() const {return fa_flushed;}
        const QString& get_fa_fly() const {return fa_fly;}
        const QString& get_fa_folder() const {return fa_folder;}
        const QString& get_fa_folder_minus() const {return fa_folder_minus;}
        const QString& get_fa_folder_open() const {return fa_folder_open;}
        const QString& get_fa_folder_plus() const {return fa_folder_plus;}
        const QString& get_fa_font() const {return fa_font;}
        const QString& get_fa_font_awesome() const {return fa_font_awesome;}
        const QString& get_fa_font_awesome_alt() const {return fa_font_awesome_alt;}
        const QString& get_fa_font_awesome_flag() const {return fa_font_awesome_flag;}
        const QString& get_fa_font_awesome_logo_full() const {return fa_font_awesome_logo_full;}
        const QString& get_fa_fonticons() const {return fa_fonticons;}
        const QString& get_fa_fonticons_fi() const {return fa_fonticons_fi;}
        const QString& get_fa_football_ball() const {return fa_football_ball;}
        const QString& get_fa_fort_awesome() const {return fa_fort_awesome;}
        const QString& get_fa_fort_awesome_alt() const {return fa_fort_awesome_alt;}
        const QString& get_fa_forumbee() const {return fa_forumbee;}
        const QString& get_fa_forward() const {return fa_forward;}
        const QString& get_fa_foursquare() const {return fa_foursquare;}
        const QString& get_fa_free_code_camp() const {return fa_free_code_camp;}
        const QString& get_fa_freebsd() const {return fa_freebsd;}
        const QString& get_fa_frog() const {return fa_frog;}
        const QString& get_fa_frown() const {return fa_frown;}
        const QString& get_fa_frown_open() const {return fa_frown_open;}
        const QString& get_fa_fulcrum() const {return fa_fulcrum;}
        const QString& get_fa_funnel_dollar() const {return fa_funnel_dollar;}
        const QString& get_fa_futbol() const {return fa_futbol;}
        const QString& get_fa_galactic_republic() const {return fa_galactic_republic;}
        const QString& get_fa_galactic_senate() const {return fa_galactic_senate;}
        const QString& get_fa_gamepad() const {return fa_gamepad;}
        const QString& get_fa_gas_pump() const {return fa_gas_pump;}
        const QString& get_fa_gavel() const {return fa_gavel;}
        const QString& get_fa_gem() const {return fa_gem;}
        const QString& get_fa_genderless() const {return fa_genderless;}
        const QString& get_fa_get_pocket() const {return fa_get_pocket;}
        const QString& get_fa_gg() const {return fa_gg;}
        const QString& get_fa_gg_circle() const {return fa_gg_circle;}
        const QString& get_fa_ghost() const {return fa_ghost;}
        const QString& get_fa_gift() const {return fa_gift;}
        const QString& get_fa_gifts() const {return fa_gifts;}
        const QString& get_fa_git() const {return fa_git;}
        const QString& get_fa_git_alt() const {return fa_git_alt;}
        const QString& get_fa_git_square() const {return fa_git_square;}
        const QString& get_fa_github() const {return fa_github;}
        const QString& get_fa_github_alt() const {return fa_github_alt;}
        const QString& get_fa_github_square() const {return fa_github_square;}
        const QString& get_fa_gitkraken() const {return fa_gitkraken;}
        const QString& get_fa_gitlab() const {return fa_gitlab;}
        const QString& get_fa_gitter() const {return fa_gitter;}
        const QString& get_fa_glass_cheers() const {return fa_glass_cheers;}
        const QString& get_fa_glass_martini() const {return fa_glass_martini;}
        const QString& get_fa_glass_martini_alt() const {return fa_glass_martini_alt;}
        const QString& get_fa_glass_whiskey() const {return fa_glass_whiskey;}
        const QString& get_fa_glasses() const {return fa_glasses;}
        const QString& get_fa_glide() const {return fa_glide;}
        const QString& get_fa_glide_g() const {return fa_glide_g;}
        const QString& get_fa_globe() const {return fa_globe;}
        const QString& get_fa_globe_africa() const {return fa_globe_africa;}
        const QString& get_fa_globe_americas() const {return fa_globe_americas;}
        const QString& get_fa_globe_asia() const {return fa_globe_asia;}
        const QString& get_fa_globe_europe() const {return fa_globe_europe;}
        const QString& get_fa_gofore() const {return fa_gofore;}
        const QString& get_fa_golf_ball() const {return fa_golf_ball;}
        const QString& get_fa_goodreads() const {return fa_goodreads;}
        const QString& get_fa_goodreads_g() const {return fa_goodreads_g;}
        const QString& get_fa_google() const {return fa_google;}
        const QString& get_fa_google_drive() const {return fa_google_drive;}
        const QString& get_fa_google_play() const {return fa_google_play;}
        const QString& get_fa_google_plus() const {return fa_google_plus;}
        const QString& get_fa_google_plus_g() const {return fa_google_plus_g;}
        const QString& get_fa_google_plus_square() const {return fa_google_plus_square;}
        const QString& get_fa_google_wallet() const {return fa_google_wallet;}
        const QString& get_fa_gopuram() const {return fa_gopuram;}
        const QString& get_fa_graduation_cap() const {return fa_graduation_cap;}
        const QString& get_fa_gratipay() const {return fa_gratipay;}
        const QString& get_fa_grav() const {return fa_grav;}
        const QString& get_fa_greater_than() const {return fa_greater_than;}
        const QString& get_fa_greater_than_equal() const {return fa_greater_than_equal;}
        const QString& get_fa_grimace() const {return fa_grimace;}
        const QString& get_fa_grin() const {return fa_grin;}
        const QString& get_fa_grin_alt() const {return fa_grin_alt;}
        const QString& get_fa_grin_beam() const {return fa_grin_beam;}
        const QString& get_fa_grin_beam_sweat() const {return fa_grin_beam_sweat;}
        const QString& get_fa_grin_hearts() const {return fa_grin_hearts;}
        const QString& get_fa_grin_squint() const {return fa_grin_squint;}
        const QString& get_fa_grin_squint_tears() const {return fa_grin_squint_tears;}
        const QString& get_fa_grin_stars() const {return fa_grin_stars;}
        const QString& get_fa_grin_tears() const {return fa_grin_tears;}
        const QString& get_fa_grin_tongue() const {return fa_grin_tongue;}
        const QString& get_fa_grin_tongue_squint() const {return fa_grin_tongue_squint;}
        const QString& get_fa_grin_tongue_wink() const {return fa_grin_tongue_wink;}
        const QString& get_fa_grin_wink() const {return fa_grin_wink;}
        const QString& get_fa_grip_horizontal() const {return fa_grip_horizontal;}
        const QString& get_fa_grip_lines() const {return fa_grip_lines;}
        const QString& get_fa_grip_lines_vertical() const {return fa_grip_lines_vertical;}
        const QString& get_fa_grip_vertical() const {return fa_grip_vertical;}
        const QString& get_fa_gripfire() const {return fa_gripfire;}
        const QString& get_fa_grunt() const {return fa_grunt;}
        const QString& get_fa_guitar() const {return fa_guitar;}
        const QString& get_fa_gulp() const {return fa_gulp;}
        const QString& get_fa_h_square() const {return fa_h_square;}
        const QString& get_fa_hacker_news() const {return fa_hacker_news;}
        const QString& get_fa_hacker_news_square() const {return fa_hacker_news_square;}
        const QString& get_fa_hackerrank() const {return fa_hackerrank;}
        const QString& get_fa_hamburger() const {return fa_hamburger;}
        const QString& get_fa_hammer() const {return fa_hammer;}
        const QString& get_fa_hamsa() const {return fa_hamsa;}
        const QString& get_fa_hand_holding() const {return fa_hand_holding;}
        const QString& get_fa_hand_holding_heart() const {return fa_hand_holding_heart;}
        const QString& get_fa_hand_holding_usd() const {return fa_hand_holding_usd;}
        const QString& get_fa_hand_lizard() const {return fa_hand_lizard;}
        const QString& get_fa_hand_middle_finger() const {return fa_hand_middle_finger;}
        const QString& get_fa_hand_paper() const {return fa_hand_paper;}
        const QString& get_fa_hand_peace() const {return fa_hand_peace;}
        const QString& get_fa_hand_point_down() const {return fa_hand_point_down;}
        const QString& get_fa_hand_point_left() const {return fa_hand_point_left;}
        const QString& get_fa_hand_point_right() const {return fa_hand_point_right;}
        const QString& get_fa_hand_point_up() const {return fa_hand_point_up;}
        const QString& get_fa_hand_pointer() const {return fa_hand_pointer;}
        const QString& get_fa_hand_rock() const {return fa_hand_rock;}
        const QString& get_fa_hand_scissors() const {return fa_hand_scissors;}
        const QString& get_fa_hand_spock() const {return fa_hand_spock;}
        const QString& get_fa_hands() const {return fa_hands;}
        const QString& get_fa_hands_helping() const {return fa_hands_helping;}
        const QString& get_fa_handshake() const {return fa_handshake;}
        const QString& get_fa_hanukiah() const {return fa_hanukiah;}
        const QString& get_fa_hard_hat() const {return fa_hard_hat;}
        const QString& get_fa_hashtag() const {return fa_hashtag;}
        const QString& get_fa_hat_cowboy() const {return fa_hat_cowboy;}
        const QString& get_fa_hat_cowboy_side() const {return fa_hat_cowboy_side;}
        const QString& get_fa_hat_wizard() const {return fa_hat_wizard;}
        const QString& get_fa_haykal() const {return fa_haykal;}
        const QString& get_fa_hdd() const {return fa_hdd;}
        const QString& get_fa_heading() const {return fa_heading;}
        const QString& get_fa_headphones() const {return fa_headphones;}
        const QString& get_fa_headphones_alt() const {return fa_headphones_alt;}
        const QString& get_fa_headset() const {return fa_headset;}
        const QString& get_fa_heart() const {return fa_heart;}
        const QString& get_fa_heart_broken() const {return fa_heart_broken;}
        const QString& get_fa_heartbeat() const {return fa_heartbeat;}
        const QString& get_fa_helicopter() const {return fa_helicopter;}
        const QString& get_fa_highlighter() const {return fa_highlighter;}
        const QString& get_fa_hiking() const {return fa_hiking;}
        const QString& get_fa_hippo() const {return fa_hippo;}
        const QString& get_fa_hips() const {return fa_hips;}
        const QString& get_fa_hire_a_helper() const {return fa_hire_a_helper;}
        const QString& get_fa_history() const {return fa_history;}
        const QString& get_fa_hockey_puck() const {return fa_hockey_puck;}
        const QString& get_fa_holly_berry() const {return fa_holly_berry;}
        const QString& get_fa_home() const {return fa_home;}
        const QString& get_fa_hooli() const {return fa_hooli;}
        const QString& get_fa_hornbill() const {return fa_hornbill;}
        const QString& get_fa_horse() const {return fa_horse;}
        const QString& get_fa_horse_head() const {return fa_horse_head;}
        const QString& get_fa_hospital() const {return fa_hospital;}
        const QString& get_fa_hospital_alt() const {return fa_hospital_alt;}
        const QString& get_fa_hospital_symbol() const {return fa_hospital_symbol;}
        const QString& get_fa_hot_tub() const {return fa_hot_tub;}
        const QString& get_fa_hotdog() const {return fa_hotdog;}
        const QString& get_fa_hotel() const {return fa_hotel;}
        const QString& get_fa_hotjar() const {return fa_hotjar;}
        const QString& get_fa_hourglass() const {return fa_hourglass;}
        const QString& get_fa_hourglass_end() const {return fa_hourglass_end;}
        const QString& get_fa_hourglass_half() const {return fa_hourglass_half;}
        const QString& get_fa_hourglass_start() const {return fa_hourglass_start;}
        const QString& get_fa_house_damage() const {return fa_house_damage;}
        const QString& get_fa_houzz() const {return fa_houzz;}
        const QString& get_fa_hryvnia() const {return fa_hryvnia;}
        const QString& get_fa_html5() const {return fa_html5;}
        const QString& get_fa_hubspot() const {return fa_hubspot;}
        const QString& get_fa_i_cursor() const {return fa_i_cursor;}
        const QString& get_fa_ice_cream() const {return fa_ice_cream;}
        const QString& get_fa_icicles() const {return fa_icicles;}
        const QString& get_fa_icons() const {return fa_icons;}
        const QString& get_fa_id_badge() const {return fa_id_badge;}
        const QString& get_fa_id_card() const {return fa_id_card;}
        const QString& get_fa_id_card_alt() const {return fa_id_card_alt;}
        const QString& get_fa_igloo() const {return fa_igloo;}
        const QString& get_fa_image() const {return fa_image;}
        const QString& get_fa_images() const {return fa_images;}
        const QString& get_fa_imdb() const {return fa_imdb;}
        const QString& get_fa_inbox() const {return fa_inbox;}
        const QString& get_fa_indent() const {return fa_indent;}
        const QString& get_fa_industry() const {return fa_industry;}
        const QString& get_fa_infinity() const {return fa_infinity;}
        const QString& get_fa_info() const {return fa_info;}
        const QString& get_fa_info_circle() const {return fa_info_circle;}
        const QString& get_fa_instagram() const {return fa_instagram;}
        const QString& get_fa_intercom() const {return fa_intercom;}
        const QString& get_fa_internet_explorer() const {return fa_internet_explorer;}
        const QString& get_fa_invision() const {return fa_invision;}
        const QString& get_fa_ioxhost() const {return fa_ioxhost;}
        const QString& get_fa_italic() const {return fa_italic;}
        const QString& get_fa_itch_io() const {return fa_itch_io;}
        const QString& get_fa_itunes() const {return fa_itunes;}
        const QString& get_fa_itunes_note() const {return fa_itunes_note;}
        const QString& get_fa_java() const {return fa_java;}
        const QString& get_fa_jedi() const {return fa_jedi;}
        const QString& get_fa_jedi_order() const {return fa_jedi_order;}
        const QString& get_fa_jenkins() const {return fa_jenkins;}
        const QString& get_fa_jira() const {return fa_jira;}
        const QString& get_fa_joget() const {return fa_joget;}
        const QString& get_fa_joint() const {return fa_joint;}
        const QString& get_fa_joomla() const {return fa_joomla;}
        const QString& get_fa_journal_whills() const {return fa_journal_whills;}
        const QString& get_fa_js() const {return fa_js;}
        const QString& get_fa_js_square() const {return fa_js_square;}
        const QString& get_fa_jsfiddle() const {return fa_jsfiddle;}
        const QString& get_fa_kaaba() const {return fa_kaaba;}
        const QString& get_fa_kaggle() const {return fa_kaggle;}
        const QString& get_fa_key() const {return fa_key;}
        const QString& get_fa_keybase() const {return fa_keybase;}
        const QString& get_fa_keyboard() const {return fa_keyboard;}
        const QString& get_fa_keycdn() const {return fa_keycdn;}
        const QString& get_fa_khanda() const {return fa_khanda;}
        const QString& get_fa_kickstarter() const {return fa_kickstarter;}
        const QString& get_fa_kickstarter_k() const {return fa_kickstarter_k;}
        const QString& get_fa_kiss() const {return fa_kiss;}
        const QString& get_fa_kiss_beam() const {return fa_kiss_beam;}
        const QString& get_fa_kiss_wink_heart() const {return fa_kiss_wink_heart;}
        const QString& get_fa_kiwi_bird() const {return fa_kiwi_bird;}
        const QString& get_fa_korvue() const {return fa_korvue;}
        const QString& get_fa_landmark() const {return fa_landmark;}
        const QString& get_fa_language() const {return fa_language;}
        const QString& get_fa_laptop() const {return fa_laptop;}
        const QString& get_fa_laptop_code() const {return fa_laptop_code;}
        const QString& get_fa_laptop_medical() const {return fa_laptop_medical;}
        const QString& get_fa_laravel() const {return fa_laravel;}
        const QString& get_fa_lastfm() const {return fa_lastfm;}
        const QString& get_fa_lastfm_square() const {return fa_lastfm_square;}
        const QString& get_fa_laugh() const {return fa_laugh;}
        const QString& get_fa_laugh_beam() const {return fa_laugh_beam;}
        const QString& get_fa_laugh_squint() const {return fa_laugh_squint;}
        const QString& get_fa_laugh_wink() const {return fa_laugh_wink;}
        const QString& get_fa_layer_group() const {return fa_layer_group;}
        const QString& get_fa_leaf() const {return fa_leaf;}
        const QString& get_fa_leanpub() const {return fa_leanpub;}
        const QString& get_fa_lemon() const {return fa_lemon;}
        const QString& get_fa_less() const {return fa_less;}
        const QString& get_fa_less_than() const {return fa_less_than;}
        const QString& get_fa_less_than_equal() const {return fa_less_than_equal;}
        const QString& get_fa_level_down_alt() const {return fa_level_down_alt;}
        const QString& get_fa_level_up_alt() const {return fa_level_up_alt;}
        const QString& get_fa_life_ring() const {return fa_life_ring;}
        const QString& get_fa_lightbulb() const {return fa_lightbulb;}
        const QString& get_fa_line() const {return fa_line;}
        const QString& get_fa_link() const {return fa_link;}
        const QString& get_fa_linkedin() const {return fa_linkedin;}
        const QString& get_fa_linkedin_in() const {return fa_linkedin_in;}
        const QString& get_fa_linode() const {return fa_linode;}
        const QString& get_fa_linux() const {return fa_linux;}
        const QString& get_fa_lira_sign() const {return fa_lira_sign;}
        const QString& get_fa_list() const {return fa_list;}
        const QString& get_fa_list_alt() const {return fa_list_alt;}
        const QString& get_fa_list_ol() const {return fa_list_ol;}
        const QString& get_fa_list_ul() const {return fa_list_ul;}
        const QString& get_fa_location_arrow() const {return fa_location_arrow;}
        const QString& get_fa_lock() const {return fa_lock;}
        const QString& get_fa_lock_open() const {return fa_lock_open;}
        const QString& get_fa_long_arrow_alt_down() const {return fa_long_arrow_alt_down;}
        const QString& get_fa_long_arrow_alt_left() const {return fa_long_arrow_alt_left;}
        const QString& get_fa_long_arrow_alt_right() const {return fa_long_arrow_alt_right;}
        const QString& get_fa_long_arrow_alt_up() const {return fa_long_arrow_alt_up;}
        const QString& get_fa_low_vision() const {return fa_low_vision;}
        const QString& get_fa_luggage_cart() const {return fa_luggage_cart;}
        const QString& get_fa_lyft() const {return fa_lyft;}
        const QString& get_fa_magento() const {return fa_magento;}
        const QString& get_fa_magic() const {return fa_magic;}
        const QString& get_fa_magnet() const {return fa_magnet;}
        const QString& get_fa_mail_bulk() const {return fa_mail_bulk;}
        const QString& get_fa_mailchimp() const {return fa_mailchimp;}
        const QString& get_fa_male() const {return fa_male;}
        const QString& get_fa_mandalorian() const {return fa_mandalorian;}
        const QString& get_fa_map() const {return fa_map;}
        const QString& get_fa_map_marked() const {return fa_map_marked;}
        const QString& get_fa_map_marked_alt() const {return fa_map_marked_alt;}
        const QString& get_fa_map_marker() const {return fa_map_marker;}
        const QString& get_fa_map_marker_alt() const {return fa_map_marker_alt;}
        const QString& get_fa_map_pin() const {return fa_map_pin;}
        const QString& get_fa_map_signs() const {return fa_map_signs;}
        const QString& get_fa_markdown() const {return fa_markdown;}
        const QString& get_fa_marker() const {return fa_marker;}
        const QString& get_fa_mars() const {return fa_mars;}
        const QString& get_fa_mars_double() const {return fa_mars_double;}
        const QString& get_fa_mars_stroke() const {return fa_mars_stroke;}
        const QString& get_fa_mars_stroke_h() const {return fa_mars_stroke_h;}
        const QString& get_fa_mars_stroke_v() const {return fa_mars_stroke_v;}
        const QString& get_fa_mask() const {return fa_mask;}
        const QString& get_fa_mastodon() const {return fa_mastodon;}
        const QString& get_fa_maxcdn() const {return fa_maxcdn;}
        const QString& get_fa_mdb() const {return fa_mdb;}
        const QString& get_fa_medal() const {return fa_medal;}
        const QString& get_fa_medapps() const {return fa_medapps;}
        const QString& get_fa_medium() const {return fa_medium;}
        const QString& get_fa_medium_m() const {return fa_medium_m;}
        const QString& get_fa_medkit() const {return fa_medkit;}
        const QString& get_fa_medrt() const {return fa_medrt;}
        const QString& get_fa_meetup() const {return fa_meetup;}
        const QString& get_fa_megaport() const {return fa_megaport;}
        const QString& get_fa_meh() const {return fa_meh;}
        const QString& get_fa_meh_blank() const {return fa_meh_blank;}
        const QString& get_fa_meh_rolling_eyes() const {return fa_meh_rolling_eyes;}
        const QString& get_fa_memory() const {return fa_memory;}
        const QString& get_fa_mendeley() const {return fa_mendeley;}
        const QString& get_fa_menorah() const {return fa_menorah;}
        const QString& get_fa_mercury() const {return fa_mercury;}
        const QString& get_fa_meteor() const {return fa_meteor;}
        const QString& get_fa_microchip() const {return fa_microchip;}
        const QString& get_fa_microphone() const {return fa_microphone;}
        const QString& get_fa_microphone_alt() const {return fa_microphone_alt;}
        const QString& get_fa_microphone_alt_slash() const {return fa_microphone_alt_slash;}
        const QString& get_fa_microphone_slash() const {return fa_microphone_slash;}
        const QString& get_fa_microscope() const {return fa_microscope;}
        const QString& get_fa_microsoft() const {return fa_microsoft;}
        const QString& get_fa_minus() const {return fa_minus;}
        const QString& get_fa_minus_circle() const {return fa_minus_circle;}
        const QString& get_fa_minus_square() const {return fa_minus_square;}
        const QString& get_fa_mitten() const {return fa_mitten;}
        const QString& get_fa_mix() const {return fa_mix;}
        const QString& get_fa_mixcloud() const {return fa_mixcloud;}
        const QString& get_fa_mizuni() const {return fa_mizuni;}
        const QString& get_fa_mobile() const {return fa_mobile;}
        const QString& get_fa_mobile_alt() const {return fa_mobile_alt;}
        const QString& get_fa_modx() const {return fa_modx;}
        const QString& get_fa_monero() const {return fa_monero;}
        const QString& get_fa_money_bill() const {return fa_money_bill;}
        const QString& get_fa_money_bill_alt() const {return fa_money_bill_alt;}
        const QString& get_fa_money_bill_wave() const {return fa_money_bill_wave;}
        const QString& get_fa_money_bill_wave_alt() const {return fa_money_bill_wave_alt;}
        const QString& get_fa_money_check() const {return fa_money_check;}
        const QString& get_fa_money_check_alt() const {return fa_money_check_alt;}
        const QString& get_fa_monument() const {return fa_monument;}
        const QString& get_fa_moon() const {return fa_moon;}
        const QString& get_fa_mortar_pestle() const {return fa_mortar_pestle;}
        const QString& get_fa_mosque() const {return fa_mosque;}
        const QString& get_fa_motorcycle() const {return fa_motorcycle;}
        const QString& get_fa_mountain() const {return fa_mountain;}
        const QString& get_fa_mouse() const {return fa_mouse;}
        const QString& get_fa_mouse_pointer() const {return fa_mouse_pointer;}
        const QString& get_fa_mug_hot() const {return fa_mug_hot;}
        const QString& get_fa_music() const {return fa_music;}
        const QString& get_fa_napster() const {return fa_napster;}
        const QString& get_fa_neos() const {return fa_neos;}
        const QString& get_fa_network_wired() const {return fa_network_wired;}
        const QString& get_fa_neuter() const {return fa_neuter;}
        const QString& get_fa_newspaper() const {return fa_newspaper;}
        const QString& get_fa_nimblr() const {return fa_nimblr;}
        const QString& get_fa_node() const {return fa_node;}
        const QString& get_fa_node_js() const {return fa_node_js;}
        const QString& get_fa_not_equal() const {return fa_not_equal;}
        const QString& get_fa_notes_medical() const {return fa_notes_medical;}
        const QString& get_fa_npm() const {return fa_npm;}
        const QString& get_fa_ns8() const {return fa_ns8;}
        const QString& get_fa_nutritionix() const {return fa_nutritionix;}
        const QString& get_fa_object_group() const {return fa_object_group;}
        const QString& get_fa_object_ungroup() const {return fa_object_ungroup;}
        const QString& get_fa_odnoklassniki() const {return fa_odnoklassniki;}
        const QString& get_fa_odnoklassniki_square() const {return fa_odnoklassniki_square;}
        const QString& get_fa_oil_can() const {return fa_oil_can;}
        const QString& get_fa_old_republic() const {return fa_old_republic;}
        const QString& get_fa_om() const {return fa_om;}
        const QString& get_fa_opencart() const {return fa_opencart;}
        const QString& get_fa_openid() const {return fa_openid;}
        const QString& get_fa_opera() const {return fa_opera;}
        const QString& get_fa_optin_monster() const {return fa_optin_monster;}
        const QString& get_fa_orcid() const {return fa_orcid;}
        const QString& get_fa_osi() const {return fa_osi;}
        const QString& get_fa_otter() const {return fa_otter;}
        const QString& get_fa_outdent() const {return fa_outdent;}
        const QString& get_fa_page4() const {return fa_page4;}
        const QString& get_fa_pagelines() const {return fa_pagelines;}
        const QString& get_fa_pager() const {return fa_pager;}
        const QString& get_fa_paint_brush() const {return fa_paint_brush;}
        const QString& get_fa_paint_roller() const {return fa_paint_roller;}
        const QString& get_fa_palette() const {return fa_palette;}
        const QString& get_fa_palfed() const {return fa_palfed;}
        const QString& get_fa_pallet() const {return fa_pallet;}
        const QString& get_fa_paper_plane() const {return fa_paper_plane;}
        const QString& get_fa_paperclip() const {return fa_paperclip;}
        const QString& get_fa_parachute_box() const {return fa_parachute_box;}
        const QString& get_fa_paragraph() const {return fa_paragraph;}
        const QString& get_fa_parking() const {return fa_parking;}
        const QString& get_fa_passport() const {return fa_passport;}
        const QString& get_fa_pastafarianism() const {return fa_pastafarianism;}
        const QString& get_fa_paste() const {return fa_paste;}
        const QString& get_fa_patreon() const {return fa_patreon;}
        const QString& get_fa_pause() const {return fa_pause;}
        const QString& get_fa_pause_circle() const {return fa_pause_circle;}
        const QString& get_fa_paw() const {return fa_paw;}
        const QString& get_fa_paypal() const {return fa_paypal;}
        const QString& get_fa_peace() const {return fa_peace;}
        const QString& get_fa_pen() const {return fa_pen;}
        const QString& get_fa_pen_alt() const {return fa_pen_alt;}
        const QString& get_fa_pen_fancy() const {return fa_pen_fancy;}
        const QString& get_fa_pen_nib() const {return fa_pen_nib;}
        const QString& get_fa_pen_square() const {return fa_pen_square;}
        const QString& get_fa_pencil_alt() const {return fa_pencil_alt;}
        const QString& get_fa_pencil_ruler() const {return fa_pencil_ruler;}
        const QString& get_fa_penny_arcade() const {return fa_penny_arcade;}
        const QString& get_fa_people_carry() const {return fa_people_carry;}
        const QString& get_fa_pepper_hot() const {return fa_pepper_hot;}
        const QString& get_fa_percent() const {return fa_percent;}
        const QString& get_fa_percentage() const {return fa_percentage;}
        const QString& get_fa_periscope() const {return fa_periscope;}
        const QString& get_fa_person_booth() const {return fa_person_booth;}
        const QString& get_fa_phabricator() const {return fa_phabricator;}
        const QString& get_fa_phoenix_framework() const {return fa_phoenix_framework;}
        const QString& get_fa_phoenix_squadron() const {return fa_phoenix_squadron;}
        const QString& get_fa_phone() const {return fa_phone;}
        const QString& get_fa_phone_alt() const {return fa_phone_alt;}
        const QString& get_fa_phone_slash() const {return fa_phone_slash;}
        const QString& get_fa_phone_square() const {return fa_phone_square;}
        const QString& get_fa_phone_square_alt() const {return fa_phone_square_alt;}
        const QString& get_fa_phone_volume() const {return fa_phone_volume;}
        const QString& get_fa_photo_video() const {return fa_photo_video;}
        const QString& get_fa_php() const {return fa_php;}
        const QString& get_fa_pied_piper() const {return fa_pied_piper;}
        const QString& get_fa_pied_piper_alt() const {return fa_pied_piper_alt;}
        const QString& get_fa_pied_piper_hat() const {return fa_pied_piper_hat;}
        const QString& get_fa_pied_piper_pp() const {return fa_pied_piper_pp;}
        const QString& get_fa_piggy_bank() const {return fa_piggy_bank;}
        const QString& get_fa_pills() const {return fa_pills;}
        const QString& get_fa_pinterest() const {return fa_pinterest;}
        const QString& get_fa_pinterest_p() const {return fa_pinterest_p;}
        const QString& get_fa_pinterest_square() const {return fa_pinterest_square;}
        const QString& get_fa_pizza_slice() const {return fa_pizza_slice;}
        const QString& get_fa_place_of_worship() const {return fa_place_of_worship;}
        const QString& get_fa_plane() const {return fa_plane;}
        const QString& get_fa_plane_arrival() const {return fa_plane_arrival;}
        const QString& get_fa_plane_departure() const {return fa_plane_departure;}
        const QString& get_fa_play() const {return fa_play;}
        const QString& get_fa_play_circle() const {return fa_play_circle;}
        const QString& get_fa_playstation() const {return fa_playstation;}
        const QString& get_fa_plug() const {return fa_plug;}
        const QString& get_fa_plus() const {return fa_plus;}
        const QString& get_fa_plus_circle() const {return fa_plus_circle;}
        const QString& get_fa_plus_square() const {return fa_plus_square;}
        const QString& get_fa_podcast() const {return fa_podcast;}
        const QString& get_fa_poll() const {return fa_poll;}
        const QString& get_fa_poll_h() const {return fa_poll_h;}
        const QString& get_fa_poo() const {return fa_poo;}
        const QString& get_fa_poo_storm() const {return fa_poo_storm;}
        const QString& get_fa_poop() const {return fa_poop;}
        const QString& get_fa_portrait() const {return fa_portrait;}
        const QString& get_fa_pound_sign() const {return fa_pound_sign;}
        const QString& get_fa_power_off() const {return fa_power_off;}
        const QString& get_fa_pray() const {return fa_pray;}
        const QString& get_fa_praying_hands() const {return fa_praying_hands;}
        const QString& get_fa_prescription() const {return fa_prescription;}
        const QString& get_fa_prescription_bottle() const {return fa_prescription_bottle;}
        const QString& get_fa_prescription_bottle_alt() const {return fa_prescription_bottle_alt;}
        const QString& get_fa_print() const {return fa_print;}
        const QString& get_fa_procedures() const {return fa_procedures;}
        const QString& get_fa_product_hunt() const {return fa_product_hunt;}
        const QString& get_fa_project_diagram() const {return fa_project_diagram;}
        const QString& get_fa_pushed() const {return fa_pushed;}
        const QString& get_fa_puzzle_piece() const {return fa_puzzle_piece;}
        const QString& get_fa_python() const {return fa_python;}
        const QString& get_fa_qq() const {return fa_qq;}
        const QString& get_fa_qrcode() const {return fa_qrcode;}
        const QString& get_fa_question() const {return fa_question;}
        const QString& get_fa_question_circle() const {return fa_question_circle;}
        const QString& get_fa_quidditch() const {return fa_quidditch;}
        const QString& get_fa_quinscape() const {return fa_quinscape;}
        const QString& get_fa_quora() const {return fa_quora;}
        const QString& get_fa_quote_left() const {return fa_quote_left;}
        const QString& get_fa_quote_right() const {return fa_quote_right;}
        const QString& get_fa_quran() const {return fa_quran;}
        const QString& get_fa_r_project() const {return fa_r_project;}
        const QString& get_fa_radiation() const {return fa_radiation;}
        const QString& get_fa_radiation_alt() const {return fa_radiation_alt;}
        const QString& get_fa_rainbow() const {return fa_rainbow;}
        const QString& get_fa_random() const {return fa_random;}
        const QString& get_fa_raspberry_pi() const {return fa_raspberry_pi;}
        const QString& get_fa_ravelry() const {return fa_ravelry;}
        const QString& get_fa_react() const {return fa_react;}
        const QString& get_fa_reacteurope() const {return fa_reacteurope;}
        const QString& get_fa_readme() const {return fa_readme;}
        const QString& get_fa_rebel() const {return fa_rebel;}
        const QString& get_fa_receipt() const {return fa_receipt;}
        const QString& get_fa_record_vinyl() const {return fa_record_vinyl;}
        const QString& get_fa_recycle() const {return fa_recycle;}
        const QString& get_fa_red_river() const {return fa_red_river;}
        const QString& get_fa_reddit() const {return fa_reddit;}
        const QString& get_fa_reddit_alien() const {return fa_reddit_alien;}
        const QString& get_fa_reddit_square() const {return fa_reddit_square;}
        const QString& get_fa_redhat() const {return fa_redhat;}
        const QString& get_fa_redo() const {return fa_redo;}
        const QString& get_fa_redo_alt() const {return fa_redo_alt;}
        const QString& get_fa_registered() const {return fa_registered;}
        const QString& get_fa_remove_format() const {return fa_remove_format;}
        const QString& get_fa_renren() const {return fa_renren;}
        const QString& get_fa_reply() const {return fa_reply;}
        const QString& get_fa_reply_all() const {return fa_reply_all;}
        const QString& get_fa_replyd() const {return fa_replyd;}
        const QString& get_fa_republican() const {return fa_republican;}
        const QString& get_fa_researchgate() const {return fa_researchgate;}
        const QString& get_fa_resolving() const {return fa_resolving;}
        const QString& get_fa_restroom() const {return fa_restroom;}
        const QString& get_fa_retweet() const {return fa_retweet;}
        const QString& get_fa_rev() const {return fa_rev;}
        const QString& get_fa_ribbon() const {return fa_ribbon;}
        const QString& get_fa_ring() const {return fa_ring;}
        const QString& get_fa_road() const {return fa_road;}
        const QString& get_fa_robot() const {return fa_robot;}
        const QString& get_fa_rocket() const {return fa_rocket;}
        const QString& get_fa_rocketchat() const {return fa_rocketchat;}
        const QString& get_fa_rockrms() const {return fa_rockrms;}
        const QString& get_fa_route() const {return fa_route;}
        const QString& get_fa_rss() const {return fa_rss;}
        const QString& get_fa_rss_square() const {return fa_rss_square;}
        const QString& get_fa_ruble_sign() const {return fa_ruble_sign;}
        const QString& get_fa_ruler() const {return fa_ruler;}
        const QString& get_fa_ruler_combined() const {return fa_ruler_combined;}
        const QString& get_fa_ruler_horizontal() const {return fa_ruler_horizontal;}
        const QString& get_fa_ruler_vertical() const {return fa_ruler_vertical;}
        const QString& get_fa_running() const {return fa_running;}
        const QString& get_fa_rupee_sign() const {return fa_rupee_sign;}
        const QString& get_fa_sad_cry() const {return fa_sad_cry;}
        const QString& get_fa_sad_tear() const {return fa_sad_tear;}
        const QString& get_fa_safari() const {return fa_safari;}
        const QString& get_fa_salesforce() const {return fa_salesforce;}
        const QString& get_fa_sass() const {return fa_sass;}
        const QString& get_fa_satellite() const {return fa_satellite;}
        const QString& get_fa_satellite_dish() const {return fa_satellite_dish;}
        const QString& get_fa_save() const {return fa_save;}
        const QString& get_fa_schlix() const {return fa_schlix;}
        const QString& get_fa_school() const {return fa_school;}
        const QString& get_fa_screwdriver() const {return fa_screwdriver;}
        const QString& get_fa_scribd() const {return fa_scribd;}
        const QString& get_fa_scroll() const {return fa_scroll;}
        const QString& get_fa_sd_card() const {return fa_sd_card;}
        const QString& get_fa_search() const {return fa_search;}
        const QString& get_fa_search_dollar() const {return fa_search_dollar;}
        const QString& get_fa_search_location() const {return fa_search_location;}
        const QString& get_fa_search_minus() const {return fa_search_minus;}
        const QString& get_fa_search_plus() const {return fa_search_plus;}
        const QString& get_fa_searchengin() const {return fa_searchengin;}
        const QString& get_fa_seedling() const {return fa_seedling;}
        const QString& get_fa_sellcast() const {return fa_sellcast;}
        const QString& get_fa_sellsy() const {return fa_sellsy;}
        const QString& get_fa_server() const {return fa_server;}
        const QString& get_fa_servicestack() const {return fa_servicestack;}
        const QString& get_fa_shapes() const {return fa_shapes;}
        const QString& get_fa_share() const {return fa_share;}
        const QString& get_fa_share_alt() const {return fa_share_alt;}
        const QString& get_fa_share_alt_square() const {return fa_share_alt_square;}
        const QString& get_fa_share_square() const {return fa_share_square;}
        const QString& get_fa_shekel_sign() const {return fa_shekel_sign;}
        const QString& get_fa_shield_alt() const {return fa_shield_alt;}
        const QString& get_fa_ship() const {return fa_ship;}
        const QString& get_fa_shipping_fast() const {return fa_shipping_fast;}
        const QString& get_fa_shirtsinbulk() const {return fa_shirtsinbulk;}
        const QString& get_fa_shoe_prints() const {return fa_shoe_prints;}
        const QString& get_fa_shopping_bag() const {return fa_shopping_bag;}
        const QString& get_fa_shopping_basket() const {return fa_shopping_basket;}
        const QString& get_fa_shopping_cart() const {return fa_shopping_cart;}
        const QString& get_fa_shopware() const {return fa_shopware;}
        const QString& get_fa_shower() const {return fa_shower;}
        const QString& get_fa_shuttle_van() const {return fa_shuttle_van;}
        const QString& get_fa_sign() const {return fa_sign;}
        const QString& get_fa_sign_in_alt() const {return fa_sign_in_alt;}
        const QString& get_fa_sign_language() const {return fa_sign_language;}
        const QString& get_fa_sign_out_alt() const {return fa_sign_out_alt;}
        const QString& get_fa_signal() const {return fa_signal;}
        const QString& get_fa_signature() const {return fa_signature;}
        const QString& get_fa_sim_card() const {return fa_sim_card;}
        const QString& get_fa_simplybuilt() const {return fa_simplybuilt;}
        const QString& get_fa_sistrix() const {return fa_sistrix;}
        const QString& get_fa_sitemap() const {return fa_sitemap;}
        const QString& get_fa_sith() const {return fa_sith;}
        const QString& get_fa_skating() const {return fa_skating;}
        const QString& get_fa_sketch() const {return fa_sketch;}
        const QString& get_fa_skiing() const {return fa_skiing;}
        const QString& get_fa_skiing_nordic() const {return fa_skiing_nordic;}
        const QString& get_fa_skull() const {return fa_skull;}
        const QString& get_fa_skull_crossbones() const {return fa_skull_crossbones;}
        const QString& get_fa_skyatlas() const {return fa_skyatlas;}
        const QString& get_fa_skype() const {return fa_skype;}
        const QString& get_fa_slack() const {return fa_slack;}
        const QString& get_fa_slack_hash() const {return fa_slack_hash;}
        const QString& get_fa_slash() const {return fa_slash;}
        const QString& get_fa_sleigh() const {return fa_sleigh;}
        const QString& get_fa_sliders_h() const {return fa_sliders_h;}
        const QString& get_fa_slideshare() const {return fa_slideshare;}
        const QString& get_fa_smile() const {return fa_smile;}
        const QString& get_fa_smile_beam() const {return fa_smile_beam;}
        const QString& get_fa_smile_wink() const {return fa_smile_wink;}
        const QString& get_fa_smog() const {return fa_smog;}
        const QString& get_fa_smoking() const {return fa_smoking;}
        const QString& get_fa_smoking_ban() const {return fa_smoking_ban;}
        const QString& get_fa_sms() const {return fa_sms;}
        const QString& get_fa_snapchat() const {return fa_snapchat;}
        const QString& get_fa_snapchat_ghost() const {return fa_snapchat_ghost;}
        const QString& get_fa_snapchat_square() const {return fa_snapchat_square;}
        const QString& get_fa_snowboarding() const {return fa_snowboarding;}
        const QString& get_fa_snowflake() const {return fa_snowflake;}
        const QString& get_fa_snowman() const {return fa_snowman;}
        const QString& get_fa_snowplow() const {return fa_snowplow;}
        const QString& get_fa_socks() const {return fa_socks;}
        const QString& get_fa_solar_panel() const {return fa_solar_panel;}
        const QString& get_fa_sort() const {return fa_sort;}
        const QString& get_fa_sort_alpha_down() const {return fa_sort_alpha_down;}
        const QString& get_fa_sort_alpha_down_alt() const {return fa_sort_alpha_down_alt;}
        const QString& get_fa_sort_alpha_up() const {return fa_sort_alpha_up;}
        const QString& get_fa_sort_alpha_up_alt() const {return fa_sort_alpha_up_alt;}
        const QString& get_fa_sort_amount_down() const {return fa_sort_amount_down;}
        const QString& get_fa_sort_amount_down_alt() const {return fa_sort_amount_down_alt;}
        const QString& get_fa_sort_amount_up() const {return fa_sort_amount_up;}
        const QString& get_fa_sort_amount_up_alt() const {return fa_sort_amount_up_alt;}
        const QString& get_fa_sort_down() const {return fa_sort_down;}
        const QString& get_fa_sort_numeric_down() const {return fa_sort_numeric_down;}
        const QString& get_fa_sort_numeric_down_alt() const {return fa_sort_numeric_down_alt;}
        const QString& get_fa_sort_numeric_up() const {return fa_sort_numeric_up;}
        const QString& get_fa_sort_numeric_up_alt() const {return fa_sort_numeric_up_alt;}
        const QString& get_fa_sort_up() const {return fa_sort_up;}
        const QString& get_fa_soundcloud() const {return fa_soundcloud;}
        const QString& get_fa_sourcetree() const {return fa_sourcetree;}
        const QString& get_fa_spa() const {return fa_spa;}
        const QString& get_fa_space_shuttle() const {return fa_space_shuttle;}
        const QString& get_fa_speakap() const {return fa_speakap;}
        const QString& get_fa_speaker_deck() const {return fa_speaker_deck;}
        const QString& get_fa_spell_check() const {return fa_spell_check;}
        const QString& get_fa_spider() const {return fa_spider;}
        const QString& get_fa_spinner() const {return fa_spinner;}
        const QString& get_fa_splotch() const {return fa_splotch;}
        const QString& get_fa_spotify() const {return fa_spotify;}
        const QString& get_fa_spray_can() const {return fa_spray_can;}
        const QString& get_fa_square() const {return fa_square;}
        const QString& get_fa_square_full() const {return fa_square_full;}
        const QString& get_fa_square_root_alt() const {return fa_square_root_alt;}
        const QString& get_fa_squarespace() const {return fa_squarespace;}
        const QString& get_fa_stack_exchange() const {return fa_stack_exchange;}
        const QString& get_fa_stack_overflow() const {return fa_stack_overflow;}
        const QString& get_fa_stackpath() const {return fa_stackpath;}
        const QString& get_fa_stamp() const {return fa_stamp;}
        const QString& get_fa_star() const {return fa_star;}
        const QString& get_fa_star_and_crescent() const {return fa_star_and_crescent;}
        const QString& get_fa_star_half() const {return fa_star_half;}
        const QString& get_fa_star_half_alt() const {return fa_star_half_alt;}
        const QString& get_fa_star_of_david() const {return fa_star_of_david;}
        const QString& get_fa_star_of_life() const {return fa_star_of_life;}
        const QString& get_fa_staylinked() const {return fa_staylinked;}
        const QString& get_fa_steam() const {return fa_steam;}
        const QString& get_fa_steam_square() const {return fa_steam_square;}
        const QString& get_fa_steam_symbol() const {return fa_steam_symbol;}
        const QString& get_fa_step_backward() const {return fa_step_backward;}
        const QString& get_fa_step_forward() const {return fa_step_forward;}
        const QString& get_fa_stethoscope() const {return fa_stethoscope;}
        const QString& get_fa_sticker_mule() const {return fa_sticker_mule;}
        const QString& get_fa_sticky_note() const {return fa_sticky_note;}
        const QString& get_fa_stop() const {return fa_stop;}
        const QString& get_fa_stop_circle() const {return fa_stop_circle;}
        const QString& get_fa_stopwatch() const {return fa_stopwatch;}
        const QString& get_fa_store() const {return fa_store;}
        const QString& get_fa_store_alt() const {return fa_store_alt;}
        const QString& get_fa_strava() const {return fa_strava;}
        const QString& get_fa_stream() const {return fa_stream;}
        const QString& get_fa_street_view() const {return fa_street_view;}
        const QString& get_fa_strikethrough() const {return fa_strikethrough;}
        const QString& get_fa_stripe() const {return fa_stripe;}
        const QString& get_fa_stripe_s() const {return fa_stripe_s;}
        const QString& get_fa_stroopwafel() const {return fa_stroopwafel;}
        const QString& get_fa_studiovinari() const {return fa_studiovinari;}
        const QString& get_fa_stumbleupon() const {return fa_stumbleupon;}
        const QString& get_fa_stumbleupon_circle() const {return fa_stumbleupon_circle;}
        const QString& get_fa_subscript() const {return fa_subscript;}
        const QString& get_fa_subway() const {return fa_subway;}
        const QString& get_fa_suitcase() const {return fa_suitcase;}
        const QString& get_fa_suitcase_rolling() const {return fa_suitcase_rolling;}
        const QString& get_fa_sun() const {return fa_sun;}
        const QString& get_fa_superpowers() const {return fa_superpowers;}
        const QString& get_fa_superscript() const {return fa_superscript;}
        const QString& get_fa_supple() const {return fa_supple;}
        const QString& get_fa_surprise() const {return fa_surprise;}
        const QString& get_fa_suse() const {return fa_suse;}
        const QString& get_fa_swatchbook() const {return fa_swatchbook;}
        const QString& get_fa_swift() const {return fa_swift;}
        const QString& get_fa_swimmer() const {return fa_swimmer;}
        const QString& get_fa_swimming_pool() const {return fa_swimming_pool;}
        const QString& get_fa_symfony() const {return fa_symfony;}
        const QString& get_fa_synagogue() const {return fa_synagogue;}
        const QString& get_fa_sync() const {return fa_sync;}
        const QString& get_fa_sync_alt() const {return fa_sync_alt;}
        const QString& get_fa_syringe() const {return fa_syringe;}
        const QString& get_fa_table() const {return fa_table;}
        const QString& get_fa_table_tennis() const {return fa_table_tennis;}
        const QString& get_fa_tablet() const {return fa_tablet;}
        const QString& get_fa_tablet_alt() const {return fa_tablet_alt;}
        const QString& get_fa_tablets() const {return fa_tablets;}
        const QString& get_fa_tachometer_alt() const {return fa_tachometer_alt;}
        const QString& get_fa_tag() const {return fa_tag;}
        const QString& get_fa_tags() const {return fa_tags;}
        const QString& get_fa_tape() const {return fa_tape;}
        const QString& get_fa_tasks() const {return fa_tasks;}
        const QString& get_fa_taxi() const {return fa_taxi;}
        const QString& get_fa_teamspeak() const {return fa_teamspeak;}
        const QString& get_fa_teeth() const {return fa_teeth;}
        const QString& get_fa_teeth_open() const {return fa_teeth_open;}
        const QString& get_fa_telegram() const {return fa_telegram;}
        const QString& get_fa_telegram_plane() const {return fa_telegram_plane;}
        const QString& get_fa_temperature_high() const {return fa_temperature_high;}
        const QString& get_fa_temperature_low() const {return fa_temperature_low;}
        const QString& get_fa_tencent_weibo() const {return fa_tencent_weibo;}
        const QString& get_fa_tenge() const {return fa_tenge;}
        const QString& get_fa_terminal() const {return fa_terminal;}
        const QString& get_fa_text_height() const {return fa_text_height;}
        const QString& get_fa_text_width() const {return fa_text_width;}
        const QString& get_fa_th() const {return fa_th;}
        const QString& get_fa_th_large() const {return fa_th_large;}
        const QString& get_fa_th_list() const {return fa_th_list;}
        const QString& get_fa_the_red_yeti() const {return fa_the_red_yeti;}
        const QString& get_fa_theater_masks() const {return fa_theater_masks;}
        const QString& get_fa_themeco() const {return fa_themeco;}
        const QString& get_fa_themeisle() const {return fa_themeisle;}
        const QString& get_fa_thermometer() const {return fa_thermometer;}
        const QString& get_fa_thermometer_empty() const {return fa_thermometer_empty;}
        const QString& get_fa_thermometer_full() const {return fa_thermometer_full;}
        const QString& get_fa_thermometer_half() const {return fa_thermometer_half;}
        const QString& get_fa_thermometer_quarter() const {return fa_thermometer_quarter;}
        const QString& get_fa_thermometer_three_quarters() const {return fa_thermometer_three_quarters;}
        const QString& get_fa_think_peaks() const {return fa_think_peaks;}
        const QString& get_fa_thumbs_down() const {return fa_thumbs_down;}
        const QString& get_fa_thumbs_up() const {return fa_thumbs_up;}
        const QString& get_fa_thumbtack() const {return fa_thumbtack;}
        const QString& get_fa_ticket_alt() const {return fa_ticket_alt;}
        const QString& get_fa_times() const {return fa_times;}
        const QString& get_fa_times_circle() const {return fa_times_circle;}
        const QString& get_fa_tint() const {return fa_tint;}
        const QString& get_fa_tint_slash() const {return fa_tint_slash;}
        const QString& get_fa_tired() const {return fa_tired;}
        const QString& get_fa_toggle_off() const {return fa_toggle_off;}
        const QString& get_fa_toggle_on() const {return fa_toggle_on;}
        const QString& get_fa_toilet() const {return fa_toilet;}
        const QString& get_fa_toilet_paper() const {return fa_toilet_paper;}
        const QString& get_fa_toolbox() const {return fa_toolbox;}
        const QString& get_fa_tools() const {return fa_tools;}
        const QString& get_fa_tooth() const {return fa_tooth;}
        const QString& get_fa_torah() const {return fa_torah;}
        const QString& get_fa_torii_gate() const {return fa_torii_gate;}
        const QString& get_fa_tractor() const {return fa_tractor;}
        const QString& get_fa_trade_federation() const {return fa_trade_federation;}
        const QString& get_fa_trademark() const {return fa_trademark;}
        const QString& get_fa_traffic_light() const {return fa_traffic_light;}
        const QString& get_fa_train() const {return fa_train;}
        const QString& get_fa_tram() const {return fa_tram;}
        const QString& get_fa_transgender() const {return fa_transgender;}
        const QString& get_fa_transgender_alt() const {return fa_transgender_alt;}
        const QString& get_fa_trash() const {return fa_trash;}
        const QString& get_fa_trash_alt() const {return fa_trash_alt;}
        const QString& get_fa_trash_restore() const {return fa_trash_restore;}
        const QString& get_fa_trash_restore_alt() const {return fa_trash_restore_alt;}
        const QString& get_fa_tree() const {return fa_tree;}
        const QString& get_fa_trello() const {return fa_trello;}
        const QString& get_fa_tripadvisor() const {return fa_tripadvisor;}
        const QString& get_fa_trophy() const {return fa_trophy;}
        const QString& get_fa_truck() const {return fa_truck;}
        const QString& get_fa_truck_loading() const {return fa_truck_loading;}
        const QString& get_fa_truck_monster() const {return fa_truck_monster;}
        const QString& get_fa_truck_moving() const {return fa_truck_moving;}
        const QString& get_fa_truck_pickup() const {return fa_truck_pickup;}
        const QString& get_fa_tshirt() const {return fa_tshirt;}
        const QString& get_fa_tty() const {return fa_tty;}
        const QString& get_fa_tumblr() const {return fa_tumblr;}
        const QString& get_fa_tumblr_square() const {return fa_tumblr_square;}
        const QString& get_fa_tv() const {return fa_tv;}
        const QString& get_fa_twitch() const {return fa_twitch;}
        const QString& get_fa_twitter() const {return fa_twitter;}
        const QString& get_fa_twitter_square() const {return fa_twitter_square;}
        const QString& get_fa_typo3() const {return fa_typo3;}
        const QString& get_fa_uber() const {return fa_uber;}
        const QString& get_fa_ubuntu() const {return fa_ubuntu;}
        const QString& get_fa_uikit() const {return fa_uikit;}
        const QString& get_fa_umbraco() const {return fa_umbraco;}
        const QString& get_fa_umbrella() const {return fa_umbrella;}
        const QString& get_fa_umbrella_beach() const {return fa_umbrella_beach;}
        const QString& get_fa_underline() const {return fa_underline;}
        const QString& get_fa_undo() const {return fa_undo;}
        const QString& get_fa_undo_alt() const {return fa_undo_alt;}
        const QString& get_fa_uniregistry() const {return fa_uniregistry;}
        const QString& get_fa_universal_access() const {return fa_universal_access;}
        const QString& get_fa_university() const {return fa_university;}
        const QString& get_fa_unlink() const {return fa_unlink;}
        const QString& get_fa_unlock() const {return fa_unlock;}
        const QString& get_fa_unlock_alt() const {return fa_unlock_alt;}
        const QString& get_fa_untappd() const {return fa_untappd;}
        const QString& get_fa_upload() const {return fa_upload;}
        const QString& get_fa_ups() const {return fa_ups;}
        const QString& get_fa_usb() const {return fa_usb;}
        const QString& get_fa_user() const {return fa_user;}
        const QString& get_fa_user_alt() const {return fa_user_alt;}
        const QString& get_fa_user_alt_slash() const {return fa_user_alt_slash;}
        const QString& get_fa_user_astronaut() const {return fa_user_astronaut;}
        const QString& get_fa_user_check() const {return fa_user_check;}
        const QString& get_fa_user_circle() const {return fa_user_circle;}
        const QString& get_fa_user_clock() const {return fa_user_clock;}
        const QString& get_fa_user_cog() const {return fa_user_cog;}
        const QString& get_fa_user_edit() const {return fa_user_edit;}
        const QString& get_fa_user_friends() const {return fa_user_friends;}
        const QString& get_fa_user_graduate() const {return fa_user_graduate;}
        const QString& get_fa_user_injured() const {return fa_user_injured;}
        const QString& get_fa_user_lock() const {return fa_user_lock;}
        const QString& get_fa_user_md() const {return fa_user_md;}
        const QString& get_fa_user_minus() const {return fa_user_minus;}
        const QString& get_fa_user_ninja() const {return fa_user_ninja;}
        const QString& get_fa_user_nurse() const {return fa_user_nurse;}
        const QString& get_fa_user_plus() const {return fa_user_plus;}
        const QString& get_fa_user_secret() const {return fa_user_secret;}
        const QString& get_fa_user_shield() const {return fa_user_shield;}
        const QString& get_fa_user_slash() const {return fa_user_slash;}
        const QString& get_fa_user_tag() const {return fa_user_tag;}
        const QString& get_fa_user_tie() const {return fa_user_tie;}
        const QString& get_fa_user_times() const {return fa_user_times;}
        const QString& get_fa_users() const {return fa_users;}
        const QString& get_fa_users_cog() const {return fa_users_cog;}
        const QString& get_fa_usps() const {return fa_usps;}
        const QString& get_fa_ussunnah() const {return fa_ussunnah;}
        const QString& get_fa_utensil_spoon() const {return fa_utensil_spoon;}
        const QString& get_fa_utensils() const {return fa_utensils;}
        const QString& get_fa_vaadin() const {return fa_vaadin;}
        const QString& get_fa_vector_square() const {return fa_vector_square;}
        const QString& get_fa_venus() const {return fa_venus;}
        const QString& get_fa_venus_double() const {return fa_venus_double;}
        const QString& get_fa_venus_mars() const {return fa_venus_mars;}
        const QString& get_fa_viacoin() const {return fa_viacoin;}
        const QString& get_fa_viadeo() const {return fa_viadeo;}
        const QString& get_fa_viadeo_square() const {return fa_viadeo_square;}
        const QString& get_fa_vial() const {return fa_vial;}
        const QString& get_fa_vials() const {return fa_vials;}
        const QString& get_fa_viber() const {return fa_viber;}
        const QString& get_fa_video() const {return fa_video;}
        const QString& get_fa_video_slash() const {return fa_video_slash;}
        const QString& get_fa_vihara() const {return fa_vihara;}
        const QString& get_fa_vimeo() const {return fa_vimeo;}
        const QString& get_fa_vimeo_square() const {return fa_vimeo_square;}
        const QString& get_fa_vimeo_v() const {return fa_vimeo_v;}
        const QString& get_fa_vine() const {return fa_vine;}
        const QString& get_fa_vk() const {return fa_vk;}
        const QString& get_fa_vnv() const {return fa_vnv;}
        const QString& get_fa_voicemail() const {return fa_voicemail;}
        const QString& get_fa_volleyball_ball() const {return fa_volleyball_ball;}
        const QString& get_fa_volume_down() const {return fa_volume_down;}
        const QString& get_fa_volume_mute() const {return fa_volume_mute;}
        const QString& get_fa_volume_off() const {return fa_volume_off;}
        const QString& get_fa_volume_up() const {return fa_volume_up;}
        const QString& get_fa_vote_yea() const {return fa_vote_yea;}
        const QString& get_fa_vr_cardboard() const {return fa_vr_cardboard;}
        const QString& get_fa_vuejs() const {return fa_vuejs;}
        const QString& get_fa_walking() const {return fa_walking;}
        const QString& get_fa_wallet() const {return fa_wallet;}
        const QString& get_fa_warehouse() const {return fa_warehouse;}
        const QString& get_fa_water() const {return fa_water;}
        const QString& get_fa_wave_square() const {return fa_wave_square;}
        const QString& get_fa_waze() const {return fa_waze;}
        const QString& get_fa_weebly() const {return fa_weebly;}
        const QString& get_fa_weibo() const {return fa_weibo;}
        const QString& get_fa_weight() const {return fa_weight;}
        const QString& get_fa_weight_hanging() const {return fa_weight_hanging;}
        const QString& get_fa_weixin() const {return fa_weixin;}
        const QString& get_fa_whatsapp() const {return fa_whatsapp;}
        const QString& get_fa_whatsapp_square() const {return fa_whatsapp_square;}
        const QString& get_fa_wheelchair() const {return fa_wheelchair;}
        const QString& get_fa_whmcs() const {return fa_whmcs;}
        const QString& get_fa_wifi() const {return fa_wifi;}
        const QString& get_fa_wikipedia_w() const {return fa_wikipedia_w;}
        const QString& get_fa_wind() const {return fa_wind;}
        const QString& get_fa_window_close() const {return fa_window_close;}
        const QString& get_fa_window_maximize() const {return fa_window_maximize;}
        const QString& get_fa_window_minimize() const {return fa_window_minimize;}
        const QString& get_fa_window_restore() const {return fa_window_restore;}
        const QString& get_fa_windows() const {return fa_windows;}
        const QString& get_fa_wine_bottle() const {return fa_wine_bottle;}
        const QString& get_fa_wine_glass() const {return fa_wine_glass;}
        const QString& get_fa_wine_glass_alt() const {return fa_wine_glass_alt;}
        const QString& get_fa_wix() const {return fa_wix;}
        const QString& get_fa_wizards_of_the_coast() const {return fa_wizards_of_the_coast;}
        const QString& get_fa_wolf_pack_battalion() const {return fa_wolf_pack_battalion;}
        const QString& get_fa_won_sign() const {return fa_won_sign;}
        const QString& get_fa_wordpress() const {return fa_wordpress;}
        const QString& get_fa_wordpress_simple() const {return fa_wordpress_simple;}
        const QString& get_fa_wpbeginner() const {return fa_wpbeginner;}
        const QString& get_fa_wpexplorer() const {return fa_wpexplorer;}
        const QString& get_fa_wpforms() const {return fa_wpforms;}
        const QString& get_fa_wpressr() const {return fa_wpressr;}
        const QString& get_fa_wrench() const {return fa_wrench;}
        const QString& get_fa_x_ray() const {return fa_x_ray;}
        const QString& get_fa_xbox() const {return fa_xbox;}
        const QString& get_fa_xing() const {return fa_xing;}
        const QString& get_fa_xing_square() const {return fa_xing_square;}
        const QString& get_fa_y_combinator() const {return fa_y_combinator;}
        const QString& get_fa_yahoo() const {return fa_yahoo;}
        const QString& get_fa_yammer() const {return fa_yammer;}
        const QString& get_fa_yandex() const {return fa_yandex;}
        const QString& get_fa_yandex_international() const {return fa_yandex_international;}
        const QString& get_fa_yarn() const {return fa_yarn;}
        const QString& get_fa_yelp() const {return fa_yelp;}
        const QString& get_fa_yen_sign() const {return fa_yen_sign;}
        const QString& get_fa_yin_yang() const {return fa_yin_yang;}
        const QString& get_fa_yoast() const {return fa_yoast;}
        const QString& get_fa_youtube() const {return fa_youtube;}
        const QString& get_fa_youtube_square() const {return fa_youtube_square;}
        const QString& get_fa_zhihu() const {return fa_zhihu;}

    protected:

        const QString fa_500px = QChar(0xf26e);
        const QString fa_accessible_icon = QChar(0xf368);
        const QString fa_accusoft = QChar(0xf369);
        const QString fa_acquisitions_incorporated = QChar(0xf6af);
        const QString fa_ad = QChar(0xf641);
        const QString fa_address_book = QChar(0xf2b9);
        const QString fa_address_card = QChar(0xf2bb);
        const QString fa_adjust = QChar(0xf042);
        const QString fa_adn = QChar(0xf170);
        const QString fa_adobe = QChar(0xf778);
        const QString fa_adversal = QChar(0xf36a);
        const QString fa_affiliatetheme = QChar(0xf36b);
        const QString fa_air_freshener = QChar(0xf5d0);
        const QString fa_airbnb = QChar(0xf834);
        const QString fa_algolia = QChar(0xf36c);
        const QString fa_align_center = QChar(0xf037);
        const QString fa_align_justify = QChar(0xf039);
        const QString fa_align_left = QChar(0xf036);
        const QString fa_align_right = QChar(0xf038);
        const QString fa_alipay = QChar(0xf642);
        const QString fa_allergies = QChar(0xf461);
        const QString fa_amazon = QChar(0xf270);
        const QString fa_amazon_pay = QChar(0xf42c);
        const QString fa_ambulance = QChar(0xf0f9);
        const QString fa_american_sign_language_interpreting = QChar(0xf2a3);
        const QString fa_amilia = QChar(0xf36d);
        const QString fa_anchor = QChar(0xf13d);
        const QString fa_android = QChar(0xf17b);
        const QString fa_angellist = QChar(0xf209);
        const QString fa_angle_double_down = QChar(0xf103);
        const QString fa_angle_double_left = QChar(0xf100);
        const QString fa_angle_double_right = QChar(0xf101);
        const QString fa_angle_double_up = QChar(0xf102);
        const QString fa_angle_down = QChar(0xf107);
        const QString fa_angle_left = QChar(0xf104);
        const QString fa_angle_right = QChar(0xf105);
        const QString fa_angle_up = QChar(0xf106);
        const QString fa_angry = QChar(0xf556);
        const QString fa_angrycreative = QChar(0xf36e);
        const QString fa_angular = QChar(0xf420);
        const QString fa_ankh = QChar(0xf644);
        const QString fa_app_store = QChar(0xf36f);
        const QString fa_app_store_ios = QChar(0xf370);
        const QString fa_apper = QChar(0xf371);
        const QString fa_apple = QChar(0xf179);
        const QString fa_apple_alt = QChar(0xf5d1);
        const QString fa_apple_pay = QChar(0xf415);
        const QString fa_archive = QChar(0xf187);
        const QString fa_archway = QChar(0xf557);
        const QString fa_arrow_alt_circle_down = QChar(0xf358);
        const QString fa_arrow_alt_circle_left = QChar(0xf359);
        const QString fa_arrow_alt_circle_right = QChar(0xf35a);
        const QString fa_arrow_alt_circle_up = QChar(0xf35b);
        const QString fa_arrow_circle_down = QChar(0xf0ab);
        const QString fa_arrow_circle_left = QChar(0xf0a8);
        const QString fa_arrow_circle_right = QChar(0xf0a9);
        const QString fa_arrow_circle_up = QChar(0xf0aa);
        const QString fa_arrow_down = QChar(0xf063);
        const QString fa_arrow_left = QChar(0xf060);
        const QString fa_arrow_right = QChar(0xf061);
        const QString fa_arrow_up = QChar(0xf062);
        const QString fa_arrows_alt = QChar(0xf0b2);
        const QString fa_arrows_alt_h = QChar(0xf337);
        const QString fa_arrows_alt_v = QChar(0xf338);
        const QString fa_artstation = QChar(0xf77a);
        const QString fa_assistive_listening_systems = QChar(0xf2a2);
        const QString fa_asterisk = QChar(0xf069);
        const QString fa_asymmetrik = QChar(0xf372);
        const QString fa_at = QChar(0xf1fa);
        const QString fa_atlas = QChar(0xf558);
        const QString fa_atlassian = QChar(0xf77b);
        const QString fa_atom = QChar(0xf5d2);
        const QString fa_audible = QChar(0xf373);
        const QString fa_audio_description = QChar(0xf29e);
        const QString fa_autoprefixer = QChar(0xf41c);
        const QString fa_avianex = QChar(0xf374);
        const QString fa_aviato = QChar(0xf421);
        const QString fa_award = QChar(0xf559);
        const QString fa_aws = QChar(0xf375);
        const QString fa_baby = QChar(0xf77c);
        const QString fa_baby_carriage = QChar(0xf77d);
        const QString fa_backspace = QChar(0xf55a);
        const QString fa_backward = QChar(0xf04a);
        const QString fa_bacon = QChar(0xf7e5);
        const QString fa_balance_scale = QChar(0xf24e);
        const QString fa_balance_scale_left = QChar(0xf515);
        const QString fa_balance_scale_right = QChar(0xf516);
        const QString fa_ban = QChar(0xf05e);
        const QString fa_band_aid = QChar(0xf462);
        const QString fa_bandcamp = QChar(0xf2d5);
        const QString fa_barcode = QChar(0xf02a);
        const QString fa_bars = QChar(0xf0c9);
        const QString fa_baseball_ball = QChar(0xf433);
        const QString fa_basketball_ball = QChar(0xf434);
        const QString fa_bath = QChar(0xf2cd);
        const QString fa_battery_empty = QChar(0xf244);
        const QString fa_battery_full = QChar(0xf240);
        const QString fa_battery_half = QChar(0xf242);
        const QString fa_battery_quarter = QChar(0xf243);
        const QString fa_battery_three_quarters = QChar(0xf241);
        const QString fa_battle_net = QChar(0xf835);
        const QString fa_bed = QChar(0xf236);
        const QString fa_beer = QChar(0xf0fc);
        const QString fa_behance = QChar(0xf1b4);
        const QString fa_behance_square = QChar(0xf1b5);
        const QString fa_bell = QChar(0xf0f3);
        const QString fa_bell_slash = QChar(0xf1f6);
        const QString fa_bezier_curve = QChar(0xf55b);
        const QString fa_bible = QChar(0xf647);
        const QString fa_bicycle = QChar(0xf206);
        const QString fa_biking = QChar(0xf84a);
        const QString fa_bimobject = QChar(0xf378);
        const QString fa_binoculars = QChar(0xf1e5);
        const QString fa_biohazard = QChar(0xf780);
        const QString fa_birthday_cake = QChar(0xf1fd);
        const QString fa_bitbucket = QChar(0xf171);
        const QString fa_bitcoin = QChar(0xf379);
        const QString fa_bity = QChar(0xf37a);
        const QString fa_black_tie = QChar(0xf27e);
        const QString fa_blackberry = QChar(0xf37b);
        const QString fa_blender = QChar(0xf517);
        const QString fa_blender_phone = QChar(0xf6b6);
        const QString fa_blind = QChar(0xf29d);
        const QString fa_blog = QChar(0xf781);
        const QString fa_blogger = QChar(0xf37c);
        const QString fa_blogger_b = QChar(0xf37d);
        const QString fa_bluetooth = QChar(0xf293);
        const QString fa_bluetooth_b = QChar(0xf294);
        const QString fa_bold = QChar(0xf032);
        const QString fa_bolt = QChar(0xf0e7);
        const QString fa_bomb = QChar(0xf1e2);
        const QString fa_bone = QChar(0xf5d7);
        const QString fa_bong = QChar(0xf55c);
        const QString fa_book = QChar(0xf02d);
        const QString fa_book_dead = QChar(0xf6b7);
        const QString fa_book_medical = QChar(0xf7e6);
        const QString fa_book_open = QChar(0xf518);
        const QString fa_book_reader = QChar(0xf5da);
        const QString fa_bookmark = QChar(0xf02e);
        const QString fa_bootstrap = QChar(0xf836);
        const QString fa_border_all = QChar(0xf84c);
        const QString fa_border_none = QChar(0xf850);
        const QString fa_border_style = QChar(0xf853);
        const QString fa_bowling_ball = QChar(0xf436);
        const QString fa_box = QChar(0xf466);
        const QString fa_box_open = QChar(0xf49e);
        const QString fa_boxes = QChar(0xf468);
        const QString fa_braille = QChar(0xf2a1);
        const QString fa_brain = QChar(0xf5dc);
        const QString fa_bread_slice = QChar(0xf7ec);
        const QString fa_briefcase = QChar(0xf0b1);
        const QString fa_briefcase_medical = QChar(0xf469);
        const QString fa_broadcast_tower = QChar(0xf519);
        const QString fa_broom = QChar(0xf51a);
        const QString fa_brush = QChar(0xf55d);
        const QString fa_btc = QChar(0xf15a);
        const QString fa_buffer = QChar(0xf837);
        const QString fa_bug = QChar(0xf188);
        const QString fa_building = QChar(0xf1ad);
        const QString fa_bullhorn = QChar(0xf0a1);
        const QString fa_bullseye = QChar(0xf140);
        const QString fa_burn = QChar(0xf46a);
        const QString fa_buromobelexperte = QChar(0xf37f);
        const QString fa_bus = QChar(0xf207);
        const QString fa_bus_alt = QChar(0xf55e);
        const QString fa_business_time = QChar(0xf64a);
        const QString fa_buy_n_large = QChar(0xf8a6);
        const QString fa_buysellads = QChar(0xf20d);
        const QString fa_calculator = QChar(0xf1ec);
        const QString fa_calendar = QChar(0xf133);
        const QString fa_calendar_alt = QChar(0xf073);
        const QString fa_calendar_check = QChar(0xf274);
        const QString fa_calendar_day = QChar(0xf783);
        const QString fa_calendar_minus = QChar(0xf272);
        const QString fa_calendar_plus = QChar(0xf271);
        const QString fa_calendar_times = QChar(0xf273);
        const QString fa_calendar_week = QChar(0xf784);
        const QString fa_camera = QChar(0xf030);
        const QString fa_camera_retro = QChar(0xf083);
        const QString fa_campground = QChar(0xf6bb);
        const QString fa_canadian_maple_leaf = QChar(0xf785);
        const QString fa_candy_cane = QChar(0xf786);
        const QString fa_cannabis = QChar(0xf55f);
        const QString fa_capsules = QChar(0xf46b);
        const QString fa_car = QChar(0xf1b9);
        const QString fa_car_alt = QChar(0xf5de);
        const QString fa_car_battery = QChar(0xf5df);
        const QString fa_car_crash = QChar(0xf5e1);
        const QString fa_car_side = QChar(0xf5e4);
        const QString fa_caret_down = QChar(0xf0d7);
        const QString fa_caret_left = QChar(0xf0d9);
        const QString fa_caret_right = QChar(0xf0da);
        const QString fa_caret_square_down = QChar(0xf150);
        const QString fa_caret_square_left = QChar(0xf191);
        const QString fa_caret_square_right = QChar(0xf152);
        const QString fa_caret_square_up = QChar(0xf151);
        const QString fa_caret_up = QChar(0xf0d8);
        const QString fa_carrot = QChar(0xf787);
        const QString fa_cart_arrow_down = QChar(0xf218);
        const QString fa_cart_plus = QChar(0xf217);
        const QString fa_cash_register = QChar(0xf788);
        const QString fa_cat = QChar(0xf6be);
        const QString fa_cc_amazon_pay = QChar(0xf42d);
        const QString fa_cc_amex = QChar(0xf1f3);
        const QString fa_cc_apple_pay = QChar(0xf416);
        const QString fa_cc_diners_club = QChar(0xf24c);
        const QString fa_cc_discover = QChar(0xf1f2);
        const QString fa_cc_jcb = QChar(0xf24b);
        const QString fa_cc_mastercard = QChar(0xf1f1);
        const QString fa_cc_paypal = QChar(0xf1f4);
        const QString fa_cc_stripe = QChar(0xf1f5);
        const QString fa_cc_visa = QChar(0xf1f0);
        const QString fa_centercode = QChar(0xf380);
        const QString fa_centos = QChar(0xf789);
        const QString fa_certificate = QChar(0xf0a3);
        const QString fa_chair = QChar(0xf6c0);
        const QString fa_chalkboard = QChar(0xf51b);
        const QString fa_chalkboard_teacher = QChar(0xf51c);
        const QString fa_charging_station = QChar(0xf5e7);
        const QString fa_chart_area = QChar(0xf1fe);
        const QString fa_chart_bar = QChar(0xf080);
        const QString fa_chart_line = QChar(0xf201);
        const QString fa_chart_pie = QChar(0xf200);
        const QString fa_check = QChar(0xf00c);
        const QString fa_check_circle = QChar(0xf058);
        const QString fa_check_double = QChar(0xf560);
        const QString fa_check_square = QChar(0xf14a);
        const QString fa_cheese = QChar(0xf7ef);
        const QString fa_chess = QChar(0xf439);
        const QString fa_chess_bishop = QChar(0xf43a);
        const QString fa_chess_board = QChar(0xf43c);
        const QString fa_chess_king = QChar(0xf43f);
        const QString fa_chess_knight = QChar(0xf441);
        const QString fa_chess_pawn = QChar(0xf443);
        const QString fa_chess_queen = QChar(0xf445);
        const QString fa_chess_rook = QChar(0xf447);
        const QString fa_chevron_circle_down = QChar(0xf13a);
        const QString fa_chevron_circle_left = QChar(0xf137);
        const QString fa_chevron_circle_right = QChar(0xf138);
        const QString fa_chevron_circle_up = QChar(0xf139);
        const QString fa_chevron_down = QChar(0xf078);
        const QString fa_chevron_left = QChar(0xf053);
        const QString fa_chevron_right = QChar(0xf054);
        const QString fa_chevron_up = QChar(0xf077);
        const QString fa_child = QChar(0xf1ae);
        const QString fa_chrome = QChar(0xf268);
        const QString fa_chromecast = QChar(0xf838);
        const QString fa_church = QChar(0xf51d);
        const QString fa_circle = QChar(0xf111);
        const QString fa_circle_notch = QChar(0xf1ce);
        const QString fa_city = QChar(0xf64f);
        const QString fa_clinic_medical = QChar(0xf7f2);
        const QString fa_clipboard = QChar(0xf328);
        const QString fa_clipboard_check = QChar(0xf46c);
        const QString fa_clipboard_list = QChar(0xf46d);
        const QString fa_clock = QChar(0xf017);
        const QString fa_clone = QChar(0xf24d);
        const QString fa_closed_captioning = QChar(0xf20a);
        const QString fa_cloud = QChar(0xf0c2);
        const QString fa_cloud_download_alt = QChar(0xf381);
        const QString fa_cloud_meatball = QChar(0xf73b);
        const QString fa_cloud_moon = QChar(0xf6c3);
        const QString fa_cloud_moon_rain = QChar(0xf73c);
        const QString fa_cloud_rain = QChar(0xf73d);
        const QString fa_cloud_showers_heavy = QChar(0xf740);
        const QString fa_cloud_sun = QChar(0xf6c4);
        const QString fa_cloud_sun_rain = QChar(0xf743);
        const QString fa_cloud_upload_alt = QChar(0xf382);
        const QString fa_cloudscale = QChar(0xf383);
        const QString fa_cloudsmith = QChar(0xf384);
        const QString fa_cloudversify = QChar(0xf385);
        const QString fa_cocktail = QChar(0xf561);
        const QString fa_code = QChar(0xf121);
        const QString fa_code_branch = QChar(0xf126);
        const QString fa_codepen = QChar(0xf1cb);
        const QString fa_codiepie = QChar(0xf284);
        const QString fa_coffee = QChar(0xf0f4);
        const QString fa_cog = QChar(0xf013);
        const QString fa_cogs = QChar(0xf085);
        const QString fa_coins = QChar(0xf51e);
        const QString fa_columns = QChar(0xf0db);
        const QString fa_comment = QChar(0xf075);
        const QString fa_comment_alt = QChar(0xf27a);
        const QString fa_comment_dollar = QChar(0xf651);
        const QString fa_comment_dots = QChar(0xf4ad);
        const QString fa_comment_medical = QChar(0xf7f5);
        const QString fa_comment_slash = QChar(0xf4b3);
        const QString fa_comments = QChar(0xf086);
        const QString fa_comments_dollar = QChar(0xf653);
        const QString fa_compact_disc = QChar(0xf51f);
        const QString fa_compass = QChar(0xf14e);
        const QString fa_compress = QChar(0xf066);
        const QString fa_compress_arrows_alt = QChar(0xf78c);
        const QString fa_concierge_bell = QChar(0xf562);
        const QString fa_confluence = QChar(0xf78d);
        const QString fa_connectdevelop = QChar(0xf20e);
        const QString fa_contao = QChar(0xf26d);
        const QString fa_cookie = QChar(0xf563);
        const QString fa_cookie_bite = QChar(0xf564);
        const QString fa_copy = QChar(0xf0c5);
        const QString fa_copyright = QChar(0xf1f9);
        const QString fa_cotton_bureau = QChar(0xf89e);
        const QString fa_couch = QChar(0xf4b8);
        const QString fa_cpanel = QChar(0xf388);
        const QString fa_creative_commons = QChar(0xf25e);
        const QString fa_creative_commons_by = QChar(0xf4e7);
        const QString fa_creative_commons_nc = QChar(0xf4e8);
        const QString fa_creative_commons_nc_eu = QChar(0xf4e9);
        const QString fa_creative_commons_nc_jp = QChar(0xf4ea);
        const QString fa_creative_commons_nd = QChar(0xf4eb);
        const QString fa_creative_commons_pd = QChar(0xf4ec);
        const QString fa_creative_commons_pd_alt = QChar(0xf4ed);
        const QString fa_creative_commons_remix = QChar(0xf4ee);
        const QString fa_creative_commons_sa = QChar(0xf4ef);
        const QString fa_creative_commons_sampling = QChar(0xf4f0);
        const QString fa_creative_commons_sampling_plus = QChar(0xf4f1);
        const QString fa_creative_commons_share = QChar(0xf4f2);
        const QString fa_creative_commons_zero = QChar(0xf4f3);
        const QString fa_credit_card = QChar(0xf09d);
        const QString fa_critical_role = QChar(0xf6c9);
        const QString fa_crop = QChar(0xf125);
        const QString fa_crop_alt = QChar(0xf565);
        const QString fa_cross = QChar(0xf654);
        const QString fa_crosshairs = QChar(0xf05b);
        const QString fa_crow = QChar(0xf520);
        const QString fa_crown = QChar(0xf521);
        const QString fa_crutch = QChar(0xf7f7);
        const QString fa_css3 = QChar(0xf13c);
        const QString fa_css3_alt = QChar(0xf38b);
        const QString fa_cube = QChar(0xf1b2);
        const QString fa_cubes = QChar(0xf1b3);
        const QString fa_cut = QChar(0xf0c4);
        const QString fa_cuttlefish = QChar(0xf38c);
        const QString fa_d_and_d = QChar(0xf38d);
        const QString fa_d_and_d_beyond = QChar(0xf6ca);
        const QString fa_dashcube = QChar(0xf210);
        const QString fa_database = QChar(0xf1c0);
        const QString fa_deaf = QChar(0xf2a4);
        const QString fa_delicious = QChar(0xf1a5);
        const QString fa_democrat = QChar(0xf747);
        const QString fa_deploydog = QChar(0xf38e);
        const QString fa_deskpro = QChar(0xf38f);
        const QString fa_desktop = QChar(0xf108);
        const QString fa_dev = QChar(0xf6cc);
        const QString fa_deviantart = QChar(0xf1bd);
        const QString fa_dharmachakra = QChar(0xf655);
        const QString fa_dhl = QChar(0xf790);
        const QString fa_diagnoses = QChar(0xf470);
        const QString fa_diaspora = QChar(0xf791);
        const QString fa_dice = QChar(0xf522);
        const QString fa_dice_d20 = QChar(0xf6cf);
        const QString fa_dice_d6 = QChar(0xf6d1);
        const QString fa_dice_five = QChar(0xf523);
        const QString fa_dice_four = QChar(0xf524);
        const QString fa_dice_one = QChar(0xf525);
        const QString fa_dice_six = QChar(0xf526);
        const QString fa_dice_three = QChar(0xf527);
        const QString fa_dice_two = QChar(0xf528);
        const QString fa_digg = QChar(0xf1a6);
        const QString fa_digital_ocean = QChar(0xf391);
        const QString fa_digital_tachograph = QChar(0xf566);
        const QString fa_directions = QChar(0xf5eb);
        const QString fa_discord = QChar(0xf392);
        const QString fa_discourse = QChar(0xf393);
        const QString fa_divide = QChar(0xf529);
        const QString fa_dizzy = QChar(0xf567);
        const QString fa_dna = QChar(0xf471);
        const QString fa_dochub = QChar(0xf394);
        const QString fa_docker = QChar(0xf395);
        const QString fa_dog = QChar(0xf6d3);
        const QString fa_dollar_sign = QChar(0xf155);
        const QString fa_dolly = QChar(0xf472);
        const QString fa_dolly_flatbed = QChar(0xf474);
        const QString fa_donate = QChar(0xf4b9);
        const QString fa_door_closed = QChar(0xf52a);
        const QString fa_door_open = QChar(0xf52b);
        const QString fa_dot_circle = QChar(0xf192);
        const QString fa_dove = QChar(0xf4ba);
        const QString fa_download = QChar(0xf019);
        const QString fa_draft2digital = QChar(0xf396);
        const QString fa_drafting_compass = QChar(0xf568);
        const QString fa_dragon = QChar(0xf6d5);
        const QString fa_draw_polygon = QChar(0xf5ee);
        const QString fa_dribbble = QChar(0xf17d);
        const QString fa_dribbble_square = QChar(0xf397);
        const QString fa_dropbox = QChar(0xf16b);
        const QString fa_drum = QChar(0xf569);
        const QString fa_drum_steelpan = QChar(0xf56a);
        const QString fa_drumstick_bite = QChar(0xf6d7);
        const QString fa_drupal = QChar(0xf1a9);
        const QString fa_dumbbell = QChar(0xf44b);
        const QString fa_dumpster = QChar(0xf793);
        const QString fa_dumpster_fire = QChar(0xf794);
        const QString fa_dungeon = QChar(0xf6d9);
        const QString fa_dyalog = QChar(0xf399);
        const QString fa_earlybirds = QChar(0xf39a);
        const QString fa_ebay = QChar(0xf4f4);
        const QString fa_edge = QChar(0xf282);
        const QString fa_edit = QChar(0xf044);
        const QString fa_egg = QChar(0xf7fb);
        const QString fa_eject = QChar(0xf052);
        const QString fa_elementor = QChar(0xf430);
        const QString fa_ellipsis_h = QChar(0xf141);
        const QString fa_ellipsis_v = QChar(0xf142);
        const QString fa_ello = QChar(0xf5f1);
        const QString fa_ember = QChar(0xf423);
        const QString fa_empire = QChar(0xf1d1);
        const QString fa_envelope = QChar(0xf0e0);
        const QString fa_envelope_open = QChar(0xf2b6);
        const QString fa_envelope_open_text = QChar(0xf658);
        const QString fa_envelope_square = QChar(0xf199);
        const QString fa_envira = QChar(0xf299);
        const QString fa_equals = QChar(0xf52c);
        const QString fa_eraser = QChar(0xf12d);
        const QString fa_erlang = QChar(0xf39d);
        const QString fa_ethereum = QChar(0xf42e);
        const QString fa_ethernet = QChar(0xf796);
        const QString fa_etsy = QChar(0xf2d7);
        const QString fa_euro_sign = QChar(0xf153);
        const QString fa_evernote = QChar(0xf839);
        const QString fa_exchange_alt = QChar(0xf362);
        const QString fa_exclamation = QChar(0xf12a);
        const QString fa_exclamation_circle = QChar(0xf06a);
        const QString fa_exclamation_triangle = QChar(0xf071);
        const QString fa_expand = QChar(0xf065);
        const QString fa_expand_arrows_alt = QChar(0xf31e);
        const QString fa_expeditedssl = QChar(0xf23e);
        const QString fa_external_link_alt = QChar(0xf35d);
        const QString fa_external_link_square_alt = QChar(0xf360);
        const QString fa_eye = QChar(0xf06e);
        const QString fa_eye_dropper = QChar(0xf1fb);
        const QString fa_eye_slash = QChar(0xf070);
        const QString fa_facebook = QChar(0xf09a);
        const QString fa_facebook_f = QChar(0xf39e);
        const QString fa_facebook_messenger = QChar(0xf39f);
        const QString fa_facebook_square = QChar(0xf082);
        const QString fa_fan = QChar(0xf863);
        const QString fa_fantasy_flight_games = QChar(0xf6dc);
        const QString fa_fast_backward = QChar(0xf049);
        const QString fa_fast_forward = QChar(0xf050);
        const QString fa_fax = QChar(0xf1ac);
        const QString fa_feather = QChar(0xf52d);
        const QString fa_feather_alt = QChar(0xf56b);
        const QString fa_fedex = QChar(0xf797);
        const QString fa_fedora = QChar(0xf798);
        const QString fa_female = QChar(0xf182);
        const QString fa_fighter_jet = QChar(0xf0fb);
        const QString fa_figma = QChar(0xf799);
        const QString fa_file = QChar(0xf15b);
        const QString fa_file_alt = QChar(0xf15c);
        const QString fa_file_archive = QChar(0xf1c6);
        const QString fa_file_audio = QChar(0xf1c7);
        const QString fa_file_code = QChar(0xf1c9);
        const QString fa_file_contract = QChar(0xf56c);
        const QString fa_file_csv = QChar(0xf6dd);
        const QString fa_file_download = QChar(0xf56d);
        const QString fa_file_excel = QChar(0xf1c3);
        const QString fa_file_export = QChar(0xf56e);
        const QString fa_file_image = QChar(0xf1c5);
        const QString fa_file_import = QChar(0xf56f);
        const QString fa_file_invoice = QChar(0xf570);
        const QString fa_file_invoice_dollar = QChar(0xf571);
        const QString fa_file_medical = QChar(0xf477);
        const QString fa_file_medical_alt = QChar(0xf478);
        const QString fa_file_pdf = QChar(0xf1c1);
        const QString fa_file_powerpoint = QChar(0xf1c4);
        const QString fa_file_prescription = QChar(0xf572);
        const QString fa_file_signature = QChar(0xf573);
        const QString fa_file_upload = QChar(0xf574);
        const QString fa_file_video = QChar(0xf1c8);
        const QString fa_file_word = QChar(0xf1c2);
        const QString fa_fill = QChar(0xf575);
        const QString fa_fill_drip = QChar(0xf576);
        const QString fa_film = QChar(0xf008);
        const QString fa_filter = QChar(0xf0b0);
        const QString fa_fingerprint = QChar(0xf577);
        const QString fa_fire = QChar(0xf06d);
        const QString fa_fire_alt = QChar(0xf7e4);
        const QString fa_fire_extinguisher = QChar(0xf134);
        const QString fa_firefox = QChar(0xf269);
        const QString fa_first_aid = QChar(0xf479);
        const QString fa_first_order = QChar(0xf2b0);
        const QString fa_first_order_alt = QChar(0xf50a);
        const QString fa_firstdraft = QChar(0xf3a1);
        const QString fa_fish = QChar(0xf578);
        const QString fa_fist_raised = QChar(0xf6de);
        const QString fa_flag = QChar(0xf024);
        const QString fa_flag_checkered = QChar(0xf11e);
        const QString fa_flag_usa = QChar(0xf74d);
        const QString fa_flask = QChar(0xf0c3);
        const QString fa_flickr = QChar(0xf16e);
        const QString fa_flipboard = QChar(0xf44d);
        const QString fa_flushed = QChar(0xf579);
        const QString fa_fly = QChar(0xf417);
        const QString fa_folder = QChar(0xf07b);
        const QString fa_folder_minus = QChar(0xf65d);
        const QString fa_folder_open = QChar(0xf07c);
        const QString fa_folder_plus = QChar(0xf65e);
        const QString fa_font = QChar(0xf031);
        const QString fa_font_awesome = QChar(0xf2b4);
        const QString fa_font_awesome_alt = QChar(0xf35c);
        const QString fa_font_awesome_flag = QChar(0xf425);
        const QString fa_font_awesome_logo_full = QChar(0xf4e6);
        const QString fa_fonticons = QChar(0xf280);
        const QString fa_fonticons_fi = QChar(0xf3a2);
        const QString fa_football_ball = QChar(0xf44e);
        const QString fa_fort_awesome = QChar(0xf286);
        const QString fa_fort_awesome_alt = QChar(0xf3a3);
        const QString fa_forumbee = QChar(0xf211);
        const QString fa_forward = QChar(0xf04e);
        const QString fa_foursquare = QChar(0xf180);
        const QString fa_free_code_camp = QChar(0xf2c5);
        const QString fa_freebsd = QChar(0xf3a4);
        const QString fa_frog = QChar(0xf52e);
        const QString fa_frown = QChar(0xf119);
        const QString fa_frown_open = QChar(0xf57a);
        const QString fa_fulcrum = QChar(0xf50b);
        const QString fa_funnel_dollar = QChar(0xf662);
        const QString fa_futbol = QChar(0xf1e3);
        const QString fa_galactic_republic = QChar(0xf50c);
        const QString fa_galactic_senate = QChar(0xf50d);
        const QString fa_gamepad = QChar(0xf11b);
        const QString fa_gas_pump = QChar(0xf52f);
        const QString fa_gavel = QChar(0xf0e3);
        const QString fa_gem = QChar(0xf3a5);
        const QString fa_genderless = QChar(0xf22d);
        const QString fa_get_pocket = QChar(0xf265);
        const QString fa_gg = QChar(0xf260);
        const QString fa_gg_circle = QChar(0xf261);
        const QString fa_ghost = QChar(0xf6e2);
        const QString fa_gift = QChar(0xf06b);
        const QString fa_gifts = QChar(0xf79c);
        const QString fa_git = QChar(0xf1d3);
        const QString fa_git_alt = QChar(0xf841);
        const QString fa_git_square = QChar(0xf1d2);
        const QString fa_github = QChar(0xf09b);
        const QString fa_github_alt = QChar(0xf113);
        const QString fa_github_square = QChar(0xf092);
        const QString fa_gitkraken = QChar(0xf3a6);
        const QString fa_gitlab = QChar(0xf296);
        const QString fa_gitter = QChar(0xf426);
        const QString fa_glass_cheers = QChar(0xf79f);
        const QString fa_glass_martini = QChar(0xf000);
        const QString fa_glass_martini_alt = QChar(0xf57b);
        const QString fa_glass_whiskey = QChar(0xf7a0);
        const QString fa_glasses = QChar(0xf530);
        const QString fa_glide = QChar(0xf2a5);
        const QString fa_glide_g = QChar(0xf2a6);
        const QString fa_globe = QChar(0xf0ac);
        const QString fa_globe_africa = QChar(0xf57c);
        const QString fa_globe_americas = QChar(0xf57d);
        const QString fa_globe_asia = QChar(0xf57e);
        const QString fa_globe_europe = QChar(0xf7a2);
        const QString fa_gofore = QChar(0xf3a7);
        const QString fa_golf_ball = QChar(0xf450);
        const QString fa_goodreads = QChar(0xf3a8);
        const QString fa_goodreads_g = QChar(0xf3a9);
        const QString fa_google = QChar(0xf1a0);
        const QString fa_google_drive = QChar(0xf3aa);
        const QString fa_google_play = QChar(0xf3ab);
        const QString fa_google_plus = QChar(0xf2b3);
        const QString fa_google_plus_g = QChar(0xf0d5);
        const QString fa_google_plus_square = QChar(0xf0d4);
        const QString fa_google_wallet = QChar(0xf1ee);
        const QString fa_gopuram = QChar(0xf664);
        const QString fa_graduation_cap = QChar(0xf19d);
        const QString fa_gratipay = QChar(0xf184);
        const QString fa_grav = QChar(0xf2d6);
        const QString fa_greater_than = QChar(0xf531);
        const QString fa_greater_than_equal = QChar(0xf532);
        const QString fa_grimace = QChar(0xf57f);
        const QString fa_grin = QChar(0xf580);
        const QString fa_grin_alt = QChar(0xf581);
        const QString fa_grin_beam = QChar(0xf582);
        const QString fa_grin_beam_sweat = QChar(0xf583);
        const QString fa_grin_hearts = QChar(0xf584);
        const QString fa_grin_squint = QChar(0xf585);
        const QString fa_grin_squint_tears = QChar(0xf586);
        const QString fa_grin_stars = QChar(0xf587);
        const QString fa_grin_tears = QChar(0xf588);
        const QString fa_grin_tongue = QChar(0xf589);
        const QString fa_grin_tongue_squint = QChar(0xf58a);
        const QString fa_grin_tongue_wink = QChar(0xf58b);
        const QString fa_grin_wink = QChar(0xf58c);
        const QString fa_grip_horizontal = QChar(0xf58d);
        const QString fa_grip_lines = QChar(0xf7a4);
        const QString fa_grip_lines_vertical = QChar(0xf7a5);
        const QString fa_grip_vertical = QChar(0xf58e);
        const QString fa_gripfire = QChar(0xf3ac);
        const QString fa_grunt = QChar(0xf3ad);
        const QString fa_guitar = QChar(0xf7a6);
        const QString fa_gulp = QChar(0xf3ae);
        const QString fa_h_square = QChar(0xf0fd);
        const QString fa_hacker_news = QChar(0xf1d4);
        const QString fa_hacker_news_square = QChar(0xf3af);
        const QString fa_hackerrank = QChar(0xf5f7);
        const QString fa_hamburger = QChar(0xf805);
        const QString fa_hammer = QChar(0xf6e3);
        const QString fa_hamsa = QChar(0xf665);
        const QString fa_hand_holding = QChar(0xf4bd);
        const QString fa_hand_holding_heart = QChar(0xf4be);
        const QString fa_hand_holding_usd = QChar(0xf4c0);
        const QString fa_hand_lizard = QChar(0xf258);
        const QString fa_hand_middle_finger = QChar(0xf806);
        const QString fa_hand_paper = QChar(0xf256);
        const QString fa_hand_peace = QChar(0xf25b);
        const QString fa_hand_point_down = QChar(0xf0a7);
        const QString fa_hand_point_left = QChar(0xf0a5);
        const QString fa_hand_point_right = QChar(0xf0a4);
        const QString fa_hand_point_up = QChar(0xf0a6);
        const QString fa_hand_pointer = QChar(0xf25a);
        const QString fa_hand_rock = QChar(0xf255);
        const QString fa_hand_scissors = QChar(0xf257);
        const QString fa_hand_spock = QChar(0xf259);
        const QString fa_hands = QChar(0xf4c2);
        const QString fa_hands_helping = QChar(0xf4c4);
        const QString fa_handshake = QChar(0xf2b5);
        const QString fa_hanukiah = QChar(0xf6e6);
        const QString fa_hard_hat = QChar(0xf807);
        const QString fa_hashtag = QChar(0xf292);
        const QString fa_hat_cowboy = QChar(0xf8c0);
        const QString fa_hat_cowboy_side = QChar(0xf8c1);
        const QString fa_hat_wizard = QChar(0xf6e8);
        const QString fa_haykal = QChar(0xf666);
        const QString fa_hdd = QChar(0xf0a0);
        const QString fa_heading = QChar(0xf1dc);
        const QString fa_headphones = QChar(0xf025);
        const QString fa_headphones_alt = QChar(0xf58f);
        const QString fa_headset = QChar(0xf590);
        const QString fa_heart = QChar(0xf004);
        const QString fa_heart_broken = QChar(0xf7a9);
        const QString fa_heartbeat = QChar(0xf21e);
        const QString fa_helicopter = QChar(0xf533);
        const QString fa_highlighter = QChar(0xf591);
        const QString fa_hiking = QChar(0xf6ec);
        const QString fa_hippo = QChar(0xf6ed);
        const QString fa_hips = QChar(0xf452);
        const QString fa_hire_a_helper = QChar(0xf3b0);
        const QString fa_history = QChar(0xf1da);
        const QString fa_hockey_puck = QChar(0xf453);
        const QString fa_holly_berry = QChar(0xf7aa);
        const QString fa_home = QChar(0xf015);
        const QString fa_hooli = QChar(0xf427);
        const QString fa_hornbill = QChar(0xf592);
        const QString fa_horse = QChar(0xf6f0);
        const QString fa_horse_head = QChar(0xf7ab);
        const QString fa_hospital = QChar(0xf0f8);
        const QString fa_hospital_alt = QChar(0xf47d);
        const QString fa_hospital_symbol = QChar(0xf47e);
        const QString fa_hot_tub = QChar(0xf593);
        const QString fa_hotdog = QChar(0xf80f);
        const QString fa_hotel = QChar(0xf594);
        const QString fa_hotjar = QChar(0xf3b1);
        const QString fa_hourglass = QChar(0xf254);
        const QString fa_hourglass_end = QChar(0xf253);
        const QString fa_hourglass_half = QChar(0xf252);
        const QString fa_hourglass_start = QChar(0xf251);
        const QString fa_house_damage = QChar(0xf6f1);
        const QString fa_houzz = QChar(0xf27c);
        const QString fa_hryvnia = QChar(0xf6f2);
        const QString fa_html5 = QChar(0xf13b);
        const QString fa_hubspot = QChar(0xf3b2);
        const QString fa_i_cursor = QChar(0xf246);
        const QString fa_ice_cream = QChar(0xf810);
        const QString fa_icicles = QChar(0xf7ad);
        const QString fa_icons = QChar(0xf86d);
        const QString fa_id_badge = QChar(0xf2c1);
        const QString fa_id_card = QChar(0xf2c2);
        const QString fa_id_card_alt = QChar(0xf47f);
        const QString fa_igloo = QChar(0xf7ae);
        const QString fa_image = QChar(0xf03e);
        const QString fa_images = QChar(0xf302);
        const QString fa_imdb = QChar(0xf2d8);
        const QString fa_inbox = QChar(0xf01c);
        const QString fa_indent = QChar(0xf03c);
        const QString fa_industry = QChar(0xf275);
        const QString fa_infinity = QChar(0xf534);
        const QString fa_info = QChar(0xf129);
        const QString fa_info_circle = QChar(0xf05a);
        const QString fa_instagram = QChar(0xf16d);
        const QString fa_intercom = QChar(0xf7af);
        const QString fa_internet_explorer = QChar(0xf26b);
        const QString fa_invision = QChar(0xf7b0);
        const QString fa_ioxhost = QChar(0xf208);
        const QString fa_italic = QChar(0xf033);
        const QString fa_itch_io = QChar(0xf83a);
        const QString fa_itunes = QChar(0xf3b4);
        const QString fa_itunes_note = QChar(0xf3b5);
        const QString fa_java = QChar(0xf4e4);
        const QString fa_jedi = QChar(0xf669);
        const QString fa_jedi_order = QChar(0xf50e);
        const QString fa_jenkins = QChar(0xf3b6);
        const QString fa_jira = QChar(0xf7b1);
        const QString fa_joget = QChar(0xf3b7);
        const QString fa_joint = QChar(0xf595);
        const QString fa_joomla = QChar(0xf1aa);
        const QString fa_journal_whills = QChar(0xf66a);
        const QString fa_js = QChar(0xf3b8);
        const QString fa_js_square = QChar(0xf3b9);
        const QString fa_jsfiddle = QChar(0xf1cc);
        const QString fa_kaaba = QChar(0xf66b);
        const QString fa_kaggle = QChar(0xf5fa);
        const QString fa_key = QChar(0xf084);
        const QString fa_keybase = QChar(0xf4f5);
        const QString fa_keyboard = QChar(0xf11c);
        const QString fa_keycdn = QChar(0xf3ba);
        const QString fa_khanda = QChar(0xf66d);
        const QString fa_kickstarter = QChar(0xf3bb);
        const QString fa_kickstarter_k = QChar(0xf3bc);
        const QString fa_kiss = QChar(0xf596);
        const QString fa_kiss_beam = QChar(0xf597);
        const QString fa_kiss_wink_heart = QChar(0xf598);
        const QString fa_kiwi_bird = QChar(0xf535);
        const QString fa_korvue = QChar(0xf42f);
        const QString fa_landmark = QChar(0xf66f);
        const QString fa_language = QChar(0xf1ab);
        const QString fa_laptop = QChar(0xf109);
        const QString fa_laptop_code = QChar(0xf5fc);
        const QString fa_laptop_medical = QChar(0xf812);
        const QString fa_laravel = QChar(0xf3bd);
        const QString fa_lastfm = QChar(0xf202);
        const QString fa_lastfm_square = QChar(0xf203);
        const QString fa_laugh = QChar(0xf599);
        const QString fa_laugh_beam = QChar(0xf59a);
        const QString fa_laugh_squint = QChar(0xf59b);
        const QString fa_laugh_wink = QChar(0xf59c);
        const QString fa_layer_group = QChar(0xf5fd);
        const QString fa_leaf = QChar(0xf06c);
        const QString fa_leanpub = QChar(0xf212);
        const QString fa_lemon = QChar(0xf094);
        const QString fa_less = QChar(0xf41d);
        const QString fa_less_than = QChar(0xf536);
        const QString fa_less_than_equal = QChar(0xf537);
        const QString fa_level_down_alt = QChar(0xf3be);
        const QString fa_level_up_alt = QChar(0xf3bf);
        const QString fa_life_ring = QChar(0xf1cd);
        const QString fa_lightbulb = QChar(0xf0eb);
        const QString fa_line = QChar(0xf3c0);
        const QString fa_link = QChar(0xf0c1);
        const QString fa_linkedin = QChar(0xf08c);
        const QString fa_linkedin_in = QChar(0xf0e1);
        const QString fa_linode = QChar(0xf2b8);
        const QString fa_linux = QChar(0xf17c);
        const QString fa_lira_sign = QChar(0xf195);
        const QString fa_list = QChar(0xf03a);
        const QString fa_list_alt = QChar(0xf022);
        const QString fa_list_ol = QChar(0xf0cb);
        const QString fa_list_ul = QChar(0xf0ca);
        const QString fa_location_arrow = QChar(0xf124);
        const QString fa_lock = QChar(0xf023);
        const QString fa_lock_open = QChar(0xf3c1);
        const QString fa_long_arrow_alt_down = QChar(0xf309);
        const QString fa_long_arrow_alt_left = QChar(0xf30a);
        const QString fa_long_arrow_alt_right = QChar(0xf30b);
        const QString fa_long_arrow_alt_up = QChar(0xf30c);
        const QString fa_low_vision = QChar(0xf2a8);
        const QString fa_luggage_cart = QChar(0xf59d);
        const QString fa_lyft = QChar(0xf3c3);
        const QString fa_magento = QChar(0xf3c4);
        const QString fa_magic = QChar(0xf0d0);
        const QString fa_magnet = QChar(0xf076);
        const QString fa_mail_bulk = QChar(0xf674);
        const QString fa_mailchimp = QChar(0xf59e);
        const QString fa_male = QChar(0xf183);
        const QString fa_mandalorian = QChar(0xf50f);
        const QString fa_map = QChar(0xf279);
        const QString fa_map_marked = QChar(0xf59f);
        const QString fa_map_marked_alt = QChar(0xf5a0);
        const QString fa_map_marker = QChar(0xf041);
        const QString fa_map_marker_alt = QChar(0xf3c5);
        const QString fa_map_pin = QChar(0xf276);
        const QString fa_map_signs = QChar(0xf277);
        const QString fa_markdown = QChar(0xf60f);
        const QString fa_marker = QChar(0xf5a1);
        const QString fa_mars = QChar(0xf222);
        const QString fa_mars_double = QChar(0xf227);
        const QString fa_mars_stroke = QChar(0xf229);
        const QString fa_mars_stroke_h = QChar(0xf22b);
        const QString fa_mars_stroke_v = QChar(0xf22a);
        const QString fa_mask = QChar(0xf6fa);
        const QString fa_mastodon = QChar(0xf4f6);
        const QString fa_maxcdn = QChar(0xf136);
        const QString fa_mdb = QChar(0xf8ca);
        const QString fa_medal = QChar(0xf5a2);
        const QString fa_medapps = QChar(0xf3c6);
        const QString fa_medium = QChar(0xf23a);
        const QString fa_medium_m = QChar(0xf3c7);
        const QString fa_medkit = QChar(0xf0fa);
        const QString fa_medrt = QChar(0xf3c8);
        const QString fa_meetup = QChar(0xf2e0);
        const QString fa_megaport = QChar(0xf5a3);
        const QString fa_meh = QChar(0xf11a);
        const QString fa_meh_blank = QChar(0xf5a4);
        const QString fa_meh_rolling_eyes = QChar(0xf5a5);
        const QString fa_memory = QChar(0xf538);
        const QString fa_mendeley = QChar(0xf7b3);
        const QString fa_menorah = QChar(0xf676);
        const QString fa_mercury = QChar(0xf223);
        const QString fa_meteor = QChar(0xf753);
        const QString fa_microchip = QChar(0xf2db);
        const QString fa_microphone = QChar(0xf130);
        const QString fa_microphone_alt = QChar(0xf3c9);
        const QString fa_microphone_alt_slash = QChar(0xf539);
        const QString fa_microphone_slash = QChar(0xf131);
        const QString fa_microscope = QChar(0xf610);
        const QString fa_microsoft = QChar(0xf3ca);
        const QString fa_minus = QChar(0xf068);
        const QString fa_minus_circle = QChar(0xf056);
        const QString fa_minus_square = QChar(0xf146);
        const QString fa_mitten = QChar(0xf7b5);
        const QString fa_mix = QChar(0xf3cb);
        const QString fa_mixcloud = QChar(0xf289);
        const QString fa_mizuni = QChar(0xf3cc);
        const QString fa_mobile = QChar(0xf10b);
        const QString fa_mobile_alt = QChar(0xf3cd);
        const QString fa_modx = QChar(0xf285);
        const QString fa_monero = QChar(0xf3d0);
        const QString fa_money_bill = QChar(0xf0d6);
        const QString fa_money_bill_alt = QChar(0xf3d1);
        const QString fa_money_bill_wave = QChar(0xf53a);
        const QString fa_money_bill_wave_alt = QChar(0xf53b);
        const QString fa_money_check = QChar(0xf53c);
        const QString fa_money_check_alt = QChar(0xf53d);
        const QString fa_monument = QChar(0xf5a6);
        const QString fa_moon = QChar(0xf186);
        const QString fa_mortar_pestle = QChar(0xf5a7);
        const QString fa_mosque = QChar(0xf678);
        const QString fa_motorcycle = QChar(0xf21c);
        const QString fa_mountain = QChar(0xf6fc);
        const QString fa_mouse = QChar(0xf8cc);
        const QString fa_mouse_pointer = QChar(0xf245);
        const QString fa_mug_hot = QChar(0xf7b6);
        const QString fa_music = QChar(0xf001);
        const QString fa_napster = QChar(0xf3d2);
        const QString fa_neos = QChar(0xf612);
        const QString fa_network_wired = QChar(0xf6ff);
        const QString fa_neuter = QChar(0xf22c);
        const QString fa_newspaper = QChar(0xf1ea);
        const QString fa_nimblr = QChar(0xf5a8);
        const QString fa_node = QChar(0xf419);
        const QString fa_node_js = QChar(0xf3d3);
        const QString fa_not_equal = QChar(0xf53e);
        const QString fa_notes_medical = QChar(0xf481);
        const QString fa_npm = QChar(0xf3d4);
        const QString fa_ns8 = QChar(0xf3d5);
        const QString fa_nutritionix = QChar(0xf3d6);
        const QString fa_object_group = QChar(0xf247);
        const QString fa_object_ungroup = QChar(0xf248);
        const QString fa_odnoklassniki = QChar(0xf263);
        const QString fa_odnoklassniki_square = QChar(0xf264);
        const QString fa_oil_can = QChar(0xf613);
        const QString fa_old_republic = QChar(0xf510);
        const QString fa_om = QChar(0xf679);
        const QString fa_opencart = QChar(0xf23d);
        const QString fa_openid = QChar(0xf19b);
        const QString fa_opera = QChar(0xf26a);
        const QString fa_optin_monster = QChar(0xf23c);
        const QString fa_orcid = QChar(0xf8d2);
        const QString fa_osi = QChar(0xf41a);
        const QString fa_otter = QChar(0xf700);
        const QString fa_outdent = QChar(0xf03b);
        const QString fa_page4 = QChar(0xf3d7);
        const QString fa_pagelines = QChar(0xf18c);
        const QString fa_pager = QChar(0xf815);
        const QString fa_paint_brush = QChar(0xf1fc);
        const QString fa_paint_roller = QChar(0xf5aa);
        const QString fa_palette = QChar(0xf53f);
        const QString fa_palfed = QChar(0xf3d8);
        const QString fa_pallet = QChar(0xf482);
        const QString fa_paper_plane = QChar(0xf1d8);
        const QString fa_paperclip = QChar(0xf0c6);
        const QString fa_parachute_box = QChar(0xf4cd);
        const QString fa_paragraph = QChar(0xf1dd);
        const QString fa_parking = QChar(0xf540);
        const QString fa_passport = QChar(0xf5ab);
        const QString fa_pastafarianism = QChar(0xf67b);
        const QString fa_paste = QChar(0xf0ea);
        const QString fa_patreon = QChar(0xf3d9);
        const QString fa_pause = QChar(0xf04c);
        const QString fa_pause_circle = QChar(0xf28b);
        const QString fa_paw = QChar(0xf1b0);
        const QString fa_paypal = QChar(0xf1ed);
        const QString fa_peace = QChar(0xf67c);
        const QString fa_pen = QChar(0xf304);
        const QString fa_pen_alt = QChar(0xf305);
        const QString fa_pen_fancy = QChar(0xf5ac);
        const QString fa_pen_nib = QChar(0xf5ad);
        const QString fa_pen_square = QChar(0xf14b);
        const QString fa_pencil_alt = QChar(0xf303);
        const QString fa_pencil_ruler = QChar(0xf5ae);
        const QString fa_penny_arcade = QChar(0xf704);
        const QString fa_people_carry = QChar(0xf4ce);
        const QString fa_pepper_hot = QChar(0xf816);
        const QString fa_percent = QChar(0xf295);
        const QString fa_percentage = QChar(0xf541);
        const QString fa_periscope = QChar(0xf3da);
        const QString fa_person_booth = QChar(0xf756);
        const QString fa_phabricator = QChar(0xf3db);
        const QString fa_phoenix_framework = QChar(0xf3dc);
        const QString fa_phoenix_squadron = QChar(0xf511);
        const QString fa_phone = QChar(0xf095);
        const QString fa_phone_alt = QChar(0xf879);
        const QString fa_phone_slash = QChar(0xf3dd);
        const QString fa_phone_square = QChar(0xf098);
        const QString fa_phone_square_alt = QChar(0xf87b);
        const QString fa_phone_volume = QChar(0xf2a0);
        const QString fa_photo_video = QChar(0xf87c);
        const QString fa_php = QChar(0xf457);
        const QString fa_pied_piper = QChar(0xf2ae);
        const QString fa_pied_piper_alt = QChar(0xf1a8);
        const QString fa_pied_piper_hat = QChar(0xf4e5);
        const QString fa_pied_piper_pp = QChar(0xf1a7);
        const QString fa_piggy_bank = QChar(0xf4d3);
        const QString fa_pills = QChar(0xf484);
        const QString fa_pinterest = QChar(0xf0d2);
        const QString fa_pinterest_p = QChar(0xf231);
        const QString fa_pinterest_square = QChar(0xf0d3);
        const QString fa_pizza_slice = QChar(0xf818);
        const QString fa_place_of_worship = QChar(0xf67f);
        const QString fa_plane = QChar(0xf072);
        const QString fa_plane_arrival = QChar(0xf5af);
        const QString fa_plane_departure = QChar(0xf5b0);
        const QString fa_play = QChar(0xf04b);
        const QString fa_play_circle = QChar(0xf144);
        const QString fa_playstation = QChar(0xf3df);
        const QString fa_plug = QChar(0xf1e6);
        const QString fa_plus = QChar(0xf067);
        const QString fa_plus_circle = QChar(0xf055);
        const QString fa_plus_square = QChar(0xf0fe);
        const QString fa_podcast = QChar(0xf2ce);
        const QString fa_poll = QChar(0xf681);
        const QString fa_poll_h = QChar(0xf682);
        const QString fa_poo = QChar(0xf2fe);
        const QString fa_poo_storm = QChar(0xf75a);
        const QString fa_poop = QChar(0xf619);
        const QString fa_portrait = QChar(0xf3e0);
        const QString fa_pound_sign = QChar(0xf154);
        const QString fa_power_off = QChar(0xf011);
        const QString fa_pray = QChar(0xf683);
        const QString fa_praying_hands = QChar(0xf684);
        const QString fa_prescription = QChar(0xf5b1);
        const QString fa_prescription_bottle = QChar(0xf485);
        const QString fa_prescription_bottle_alt = QChar(0xf486);
        const QString fa_print = QChar(0xf02f);
        const QString fa_procedures = QChar(0xf487);
        const QString fa_product_hunt = QChar(0xf288);
        const QString fa_project_diagram = QChar(0xf542);
        const QString fa_pushed = QChar(0xf3e1);
        const QString fa_puzzle_piece = QChar(0xf12e);
        const QString fa_python = QChar(0xf3e2);
        const QString fa_qq = QChar(0xf1d6);
        const QString fa_qrcode = QChar(0xf029);
        const QString fa_question = QChar(0xf128);
        const QString fa_question_circle = QChar(0xf059);
        const QString fa_quidditch = QChar(0xf458);
        const QString fa_quinscape = QChar(0xf459);
        const QString fa_quora = QChar(0xf2c4);
        const QString fa_quote_left = QChar(0xf10d);
        const QString fa_quote_right = QChar(0xf10e);
        const QString fa_quran = QChar(0xf687);
        const QString fa_r_project = QChar(0xf4f7);
        const QString fa_radiation = QChar(0xf7b9);
        const QString fa_radiation_alt = QChar(0xf7ba);
        const QString fa_rainbow = QChar(0xf75b);
        const QString fa_random = QChar(0xf074);
        const QString fa_raspberry_pi = QChar(0xf7bb);
        const QString fa_ravelry = QChar(0xf2d9);
        const QString fa_react = QChar(0xf41b);
        const QString fa_reacteurope = QChar(0xf75d);
        const QString fa_readme = QChar(0xf4d5);
        const QString fa_rebel = QChar(0xf1d0);
        const QString fa_receipt = QChar(0xf543);
        const QString fa_record_vinyl = QChar(0xf8d9);
        const QString fa_recycle = QChar(0xf1b8);
        const QString fa_red_river = QChar(0xf3e3);
        const QString fa_reddit = QChar(0xf1a1);
        const QString fa_reddit_alien = QChar(0xf281);
        const QString fa_reddit_square = QChar(0xf1a2);
        const QString fa_redhat = QChar(0xf7bc);
        const QString fa_redo = QChar(0xf01e);
        const QString fa_redo_alt = QChar(0xf2f9);
        const QString fa_registered = QChar(0xf25d);
        const QString fa_remove_format = QChar(0xf87d);
        const QString fa_renren = QChar(0xf18b);
        const QString fa_reply = QChar(0xf3e5);
        const QString fa_reply_all = QChar(0xf122);
        const QString fa_replyd = QChar(0xf3e6);
        const QString fa_republican = QChar(0xf75e);
        const QString fa_researchgate = QChar(0xf4f8);
        const QString fa_resolving = QChar(0xf3e7);
        const QString fa_restroom = QChar(0xf7bd);
        const QString fa_retweet = QChar(0xf079);
        const QString fa_rev = QChar(0xf5b2);
        const QString fa_ribbon = QChar(0xf4d6);
        const QString fa_ring = QChar(0xf70b);
        const QString fa_road = QChar(0xf018);
        const QString fa_robot = QChar(0xf544);
        const QString fa_rocket = QChar(0xf135);
        const QString fa_rocketchat = QChar(0xf3e8);
        const QString fa_rockrms = QChar(0xf3e9);
        const QString fa_route = QChar(0xf4d7);
        const QString fa_rss = QChar(0xf09e);
        const QString fa_rss_square = QChar(0xf143);
        const QString fa_ruble_sign = QChar(0xf158);
        const QString fa_ruler = QChar(0xf545);
        const QString fa_ruler_combined = QChar(0xf546);
        const QString fa_ruler_horizontal = QChar(0xf547);
        const QString fa_ruler_vertical = QChar(0xf548);
        const QString fa_running = QChar(0xf70c);
        const QString fa_rupee_sign = QChar(0xf156);
        const QString fa_sad_cry = QChar(0xf5b3);
        const QString fa_sad_tear = QChar(0xf5b4);
        const QString fa_safari = QChar(0xf267);
        const QString fa_salesforce = QChar(0xf83b);
        const QString fa_sass = QChar(0xf41e);
        const QString fa_satellite = QChar(0xf7bf);
        const QString fa_satellite_dish = QChar(0xf7c0);
        const QString fa_save = QChar(0xf0c7);
        const QString fa_schlix = QChar(0xf3ea);
        const QString fa_school = QChar(0xf549);
        const QString fa_screwdriver = QChar(0xf54a);
        const QString fa_scribd = QChar(0xf28a);
        const QString fa_scroll = QChar(0xf70e);
        const QString fa_sd_card = QChar(0xf7c2);
        const QString fa_search = QChar(0xf002);
        const QString fa_search_dollar = QChar(0xf688);
        const QString fa_search_location = QChar(0xf689);
        const QString fa_search_minus = QChar(0xf010);
        const QString fa_search_plus = QChar(0xf00e);
        const QString fa_searchengin = QChar(0xf3eb);
        const QString fa_seedling = QChar(0xf4d8);
        const QString fa_sellcast = QChar(0xf2da);
        const QString fa_sellsy = QChar(0xf213);
        const QString fa_server = QChar(0xf233);
        const QString fa_servicestack = QChar(0xf3ec);
        const QString fa_shapes = QChar(0xf61f);
        const QString fa_share = QChar(0xf064);
        const QString fa_share_alt = QChar(0xf1e0);
        const QString fa_share_alt_square = QChar(0xf1e1);
        const QString fa_share_square = QChar(0xf14d);
        const QString fa_shekel_sign = QChar(0xf20b);
        const QString fa_shield_alt = QChar(0xf3ed);
        const QString fa_ship = QChar(0xf21a);
        const QString fa_shipping_fast = QChar(0xf48b);
        const QString fa_shirtsinbulk = QChar(0xf214);
        const QString fa_shoe_prints = QChar(0xf54b);
        const QString fa_shopping_bag = QChar(0xf290);
        const QString fa_shopping_basket = QChar(0xf291);
        const QString fa_shopping_cart = QChar(0xf07a);
        const QString fa_shopware = QChar(0xf5b5);
        const QString fa_shower = QChar(0xf2cc);
        const QString fa_shuttle_van = QChar(0xf5b6);
        const QString fa_sign = QChar(0xf4d9);
        const QString fa_sign_in_alt = QChar(0xf2f6);
        const QString fa_sign_language = QChar(0xf2a7);
        const QString fa_sign_out_alt = QChar(0xf2f5);
        const QString fa_signal = QChar(0xf012);
        const QString fa_signature = QChar(0xf5b7);
        const QString fa_sim_card = QChar(0xf7c4);
        const QString fa_simplybuilt = QChar(0xf215);
        const QString fa_sistrix = QChar(0xf3ee);
        const QString fa_sitemap = QChar(0xf0e8);
        const QString fa_sith = QChar(0xf512);
        const QString fa_skating = QChar(0xf7c5);
        const QString fa_sketch = QChar(0xf7c6);
        const QString fa_skiing = QChar(0xf7c9);
        const QString fa_skiing_nordic = QChar(0xf7ca);
        const QString fa_skull = QChar(0xf54c);
        const QString fa_skull_crossbones = QChar(0xf714);
        const QString fa_skyatlas = QChar(0xf216);
        const QString fa_skype = QChar(0xf17e);
        const QString fa_slack = QChar(0xf198);
        const QString fa_slack_hash = QChar(0xf3ef);
        const QString fa_slash = QChar(0xf715);
        const QString fa_sleigh = QChar(0xf7cc);
        const QString fa_sliders_h = QChar(0xf1de);
        const QString fa_slideshare = QChar(0xf1e7);
        const QString fa_smile = QChar(0xf118);
        const QString fa_smile_beam = QChar(0xf5b8);
        const QString fa_smile_wink = QChar(0xf4da);
        const QString fa_smog = QChar(0xf75f);
        const QString fa_smoking = QChar(0xf48d);
        const QString fa_smoking_ban = QChar(0xf54d);
        const QString fa_sms = QChar(0xf7cd);
        const QString fa_snapchat = QChar(0xf2ab);
        const QString fa_snapchat_ghost = QChar(0xf2ac);
        const QString fa_snapchat_square = QChar(0xf2ad);
        const QString fa_snowboarding = QChar(0xf7ce);
        const QString fa_snowflake = QChar(0xf2dc);
        const QString fa_snowman = QChar(0xf7d0);
        const QString fa_snowplow = QChar(0xf7d2);
        const QString fa_socks = QChar(0xf696);
        const QString fa_solar_panel = QChar(0xf5ba);
        const QString fa_sort = QChar(0xf0dc);
        const QString fa_sort_alpha_down = QChar(0xf15d);
        const QString fa_sort_alpha_down_alt = QChar(0xf881);
        const QString fa_sort_alpha_up = QChar(0xf15e);
        const QString fa_sort_alpha_up_alt = QChar(0xf882);
        const QString fa_sort_amount_down = QChar(0xf160);
        const QString fa_sort_amount_down_alt = QChar(0xf884);
        const QString fa_sort_amount_up = QChar(0xf161);
        const QString fa_sort_amount_up_alt = QChar(0xf885);
        const QString fa_sort_down = QChar(0xf0dd);
        const QString fa_sort_numeric_down = QChar(0xf162);
        const QString fa_sort_numeric_down_alt = QChar(0xf886);
        const QString fa_sort_numeric_up = QChar(0xf163);
        const QString fa_sort_numeric_up_alt = QChar(0xf887);
        const QString fa_sort_up = QChar(0xf0de);
        const QString fa_soundcloud = QChar(0xf1be);
        const QString fa_sourcetree = QChar(0xf7d3);
        const QString fa_spa = QChar(0xf5bb);
        const QString fa_space_shuttle = QChar(0xf197);
        const QString fa_speakap = QChar(0xf3f3);
        const QString fa_speaker_deck = QChar(0xf83c);
        const QString fa_spell_check = QChar(0xf891);
        const QString fa_spider = QChar(0xf717);
        const QString fa_spinner = QChar(0xf110);
        const QString fa_splotch = QChar(0xf5bc);
        const QString fa_spotify = QChar(0xf1bc);
        const QString fa_spray_can = QChar(0xf5bd);
        const QString fa_square = QChar(0xf0c8);
        const QString fa_square_full = QChar(0xf45c);
        const QString fa_square_root_alt = QChar(0xf698);
        const QString fa_squarespace = QChar(0xf5be);
        const QString fa_stack_exchange = QChar(0xf18d);
        const QString fa_stack_overflow = QChar(0xf16c);
        const QString fa_stackpath = QChar(0xf842);
        const QString fa_stamp = QChar(0xf5bf);
        const QString fa_star = QChar(0xf005);
        const QString fa_star_and_crescent = QChar(0xf699);
        const QString fa_star_half = QChar(0xf089);
        const QString fa_star_half_alt = QChar(0xf5c0);
        const QString fa_star_of_david = QChar(0xf69a);
        const QString fa_star_of_life = QChar(0xf621);
        const QString fa_staylinked = QChar(0xf3f5);
        const QString fa_steam = QChar(0xf1b6);
        const QString fa_steam_square = QChar(0xf1b7);
        const QString fa_steam_symbol = QChar(0xf3f6);
        const QString fa_step_backward = QChar(0xf048);
        const QString fa_step_forward = QChar(0xf051);
        const QString fa_stethoscope = QChar(0xf0f1);
        const QString fa_sticker_mule = QChar(0xf3f7);
        const QString fa_sticky_note = QChar(0xf249);
        const QString fa_stop = QChar(0xf04d);
        const QString fa_stop_circle = QChar(0xf28d);
        const QString fa_stopwatch = QChar(0xf2f2);
        const QString fa_store = QChar(0xf54e);
        const QString fa_store_alt = QChar(0xf54f);
        const QString fa_strava = QChar(0xf428);
        const QString fa_stream = QChar(0xf550);
        const QString fa_street_view = QChar(0xf21d);
        const QString fa_strikethrough = QChar(0xf0cc);
        const QString fa_stripe = QChar(0xf429);
        const QString fa_stripe_s = QChar(0xf42a);
        const QString fa_stroopwafel = QChar(0xf551);
        const QString fa_studiovinari = QChar(0xf3f8);
        const QString fa_stumbleupon = QChar(0xf1a4);
        const QString fa_stumbleupon_circle = QChar(0xf1a3);
        const QString fa_subscript = QChar(0xf12c);
        const QString fa_subway = QChar(0xf239);
        const QString fa_suitcase = QChar(0xf0f2);
        const QString fa_suitcase_rolling = QChar(0xf5c1);
        const QString fa_sun = QChar(0xf185);
        const QString fa_superpowers = QChar(0xf2dd);
        const QString fa_superscript = QChar(0xf12b);
        const QString fa_supple = QChar(0xf3f9);
        const QString fa_surprise = QChar(0xf5c2);
        const QString fa_suse = QChar(0xf7d6);
        const QString fa_swatchbook = QChar(0xf5c3);
        const QString fa_swift = QChar(0xf8e1);
        const QString fa_swimmer = QChar(0xf5c4);
        const QString fa_swimming_pool = QChar(0xf5c5);
        const QString fa_symfony = QChar(0xf83d);
        const QString fa_synagogue = QChar(0xf69b);
        const QString fa_sync = QChar(0xf021);
        const QString fa_sync_alt = QChar(0xf2f1);
        const QString fa_syringe = QChar(0xf48e);
        const QString fa_table = QChar(0xf0ce);
        const QString fa_table_tennis = QChar(0xf45d);
        const QString fa_tablet = QChar(0xf10a);
        const QString fa_tablet_alt = QChar(0xf3fa);
        const QString fa_tablets = QChar(0xf490);
        const QString fa_tachometer_alt = QChar(0xf3fd);
        const QString fa_tag = QChar(0xf02b);
        const QString fa_tags = QChar(0xf02c);
        const QString fa_tape = QChar(0xf4db);
        const QString fa_tasks = QChar(0xf0ae);
        const QString fa_taxi = QChar(0xf1ba);
        const QString fa_teamspeak = QChar(0xf4f9);
        const QString fa_teeth = QChar(0xf62e);
        const QString fa_teeth_open = QChar(0xf62f);
        const QString fa_telegram = QChar(0xf2c6);
        const QString fa_telegram_plane = QChar(0xf3fe);
        const QString fa_temperature_high = QChar(0xf769);
        const QString fa_temperature_low = QChar(0xf76b);
        const QString fa_tencent_weibo = QChar(0xf1d5);
        const QString fa_tenge = QChar(0xf7d7);
        const QString fa_terminal = QChar(0xf120);
        const QString fa_text_height = QChar(0xf034);
        const QString fa_text_width = QChar(0xf035);
        const QString fa_th = QChar(0xf00a);
        const QString fa_th_large = QChar(0xf009);
        const QString fa_th_list = QChar(0xf00b);
        const QString fa_the_red_yeti = QChar(0xf69d);
        const QString fa_theater_masks = QChar(0xf630);
        const QString fa_themeco = QChar(0xf5c6);
        const QString fa_themeisle = QChar(0xf2b2);
        const QString fa_thermometer = QChar(0xf491);
        const QString fa_thermometer_empty = QChar(0xf2cb);
        const QString fa_thermometer_full = QChar(0xf2c7);
        const QString fa_thermometer_half = QChar(0xf2c9);
        const QString fa_thermometer_quarter = QChar(0xf2ca);
        const QString fa_thermometer_three_quarters = QChar(0xf2c8);
        const QString fa_think_peaks = QChar(0xf731);
        const QString fa_thumbs_down = QChar(0xf165);
        const QString fa_thumbs_up = QChar(0xf164);
        const QString fa_thumbtack = QChar(0xf08d);
        const QString fa_ticket_alt = QChar(0xf3ff);
        const QString fa_times = QChar(0xf00d);
        const QString fa_times_circle = QChar(0xf057);
        const QString fa_tint = QChar(0xf043);
        const QString fa_tint_slash = QChar(0xf5c7);
        const QString fa_tired = QChar(0xf5c8);
        const QString fa_toggle_off = QChar(0xf204);
        const QString fa_toggle_on = QChar(0xf205);
        const QString fa_toilet = QChar(0xf7d8);
        const QString fa_toilet_paper = QChar(0xf71e);
        const QString fa_toolbox = QChar(0xf552);
        const QString fa_tools = QChar(0xf7d9);
        const QString fa_tooth = QChar(0xf5c9);
        const QString fa_torah = QChar(0xf6a0);
        const QString fa_torii_gate = QChar(0xf6a1);
        const QString fa_tractor = QChar(0xf722);
        const QString fa_trade_federation = QChar(0xf513);
        const QString fa_trademark = QChar(0xf25c);
        const QString fa_traffic_light = QChar(0xf637);
        const QString fa_train = QChar(0xf238);
        const QString fa_tram = QChar(0xf7da);
        const QString fa_transgender = QChar(0xf224);
        const QString fa_transgender_alt = QChar(0xf225);
        const QString fa_trash = QChar(0xf1f8);
        const QString fa_trash_alt = QChar(0xf2ed);
        const QString fa_trash_restore = QChar(0xf829);
        const QString fa_trash_restore_alt = QChar(0xf82a);
        const QString fa_tree = QChar(0xf1bb);
        const QString fa_trello = QChar(0xf181);
        const QString fa_tripadvisor = QChar(0xf262);
        const QString fa_trophy = QChar(0xf091);
        const QString fa_truck = QChar(0xf0d1);
        const QString fa_truck_loading = QChar(0xf4de);
        const QString fa_truck_monster = QChar(0xf63b);
        const QString fa_truck_moving = QChar(0xf4df);
        const QString fa_truck_pickup = QChar(0xf63c);
        const QString fa_tshirt = QChar(0xf553);
        const QString fa_tty = QChar(0xf1e4);
        const QString fa_tumblr = QChar(0xf173);
        const QString fa_tumblr_square = QChar(0xf174);
        const QString fa_tv = QChar(0xf26c);
        const QString fa_twitch = QChar(0xf1e8);
        const QString fa_twitter = QChar(0xf099);
        const QString fa_twitter_square = QChar(0xf081);
        const QString fa_typo3 = QChar(0xf42b);
        const QString fa_uber = QChar(0xf402);
        const QString fa_ubuntu = QChar(0xf7df);
        const QString fa_uikit = QChar(0xf403);
        const QString fa_umbraco = QChar(0xf8e8);
        const QString fa_umbrella = QChar(0xf0e9);
        const QString fa_umbrella_beach = QChar(0xf5ca);
        const QString fa_underline = QChar(0xf0cd);
        const QString fa_undo = QChar(0xf0e2);
        const QString fa_undo_alt = QChar(0xf2ea);
        const QString fa_uniregistry = QChar(0xf404);
        const QString fa_universal_access = QChar(0xf29a);
        const QString fa_university = QChar(0xf19c);
        const QString fa_unlink = QChar(0xf127);
        const QString fa_unlock = QChar(0xf09c);
        const QString fa_unlock_alt = QChar(0xf13e);
        const QString fa_untappd = QChar(0xf405);
        const QString fa_upload = QChar(0xf093);
        const QString fa_ups = QChar(0xf7e0);
        const QString fa_usb = QChar(0xf287);
        const QString fa_user = QChar(0xf007);
        const QString fa_user_alt = QChar(0xf406);
        const QString fa_user_alt_slash = QChar(0xf4fa);
        const QString fa_user_astronaut = QChar(0xf4fb);
        const QString fa_user_check = QChar(0xf4fc);
        const QString fa_user_circle = QChar(0xf2bd);
        const QString fa_user_clock = QChar(0xf4fd);
        const QString fa_user_cog = QChar(0xf4fe);
        const QString fa_user_edit = QChar(0xf4ff);
        const QString fa_user_friends = QChar(0xf500);
        const QString fa_user_graduate = QChar(0xf501);
        const QString fa_user_injured = QChar(0xf728);
        const QString fa_user_lock = QChar(0xf502);
        const QString fa_user_md = QChar(0xf0f0);
        const QString fa_user_minus = QChar(0xf503);
        const QString fa_user_ninja = QChar(0xf504);
        const QString fa_user_nurse = QChar(0xf82f);
        const QString fa_user_plus = QChar(0xf234);
        const QString fa_user_secret = QChar(0xf21b);
        const QString fa_user_shield = QChar(0xf505);
        const QString fa_user_slash = QChar(0xf506);
        const QString fa_user_tag = QChar(0xf507);
        const QString fa_user_tie = QChar(0xf508);
        const QString fa_user_times = QChar(0xf235);
        const QString fa_users = QChar(0xf0c0);
        const QString fa_users_cog = QChar(0xf509);
        const QString fa_usps = QChar(0xf7e1);
        const QString fa_ussunnah = QChar(0xf407);
        const QString fa_utensil_spoon = QChar(0xf2e5);
        const QString fa_utensils = QChar(0xf2e7);
        const QString fa_vaadin = QChar(0xf408);
        const QString fa_vector_square = QChar(0xf5cb);
        const QString fa_venus = QChar(0xf221);
        const QString fa_venus_double = QChar(0xf226);
        const QString fa_venus_mars = QChar(0xf228);
        const QString fa_viacoin = QChar(0xf237);
        const QString fa_viadeo = QChar(0xf2a9);
        const QString fa_viadeo_square = QChar(0xf2aa);
        const QString fa_vial = QChar(0xf492);
        const QString fa_vials = QChar(0xf493);
        const QString fa_viber = QChar(0xf409);
        const QString fa_video = QChar(0xf03d);
        const QString fa_video_slash = QChar(0xf4e2);
        const QString fa_vihara = QChar(0xf6a7);
        const QString fa_vimeo = QChar(0xf40a);
        const QString fa_vimeo_square = QChar(0xf194);
        const QString fa_vimeo_v = QChar(0xf27d);
        const QString fa_vine = QChar(0xf1ca);
        const QString fa_vk = QChar(0xf189);
        const QString fa_vnv = QChar(0xf40b);
        const QString fa_voicemail = QChar(0xf897);
        const QString fa_volleyball_ball = QChar(0xf45f);
        const QString fa_volume_down = QChar(0xf027);
        const QString fa_volume_mute = QChar(0xf6a9);
        const QString fa_volume_off = QChar(0xf026);
        const QString fa_volume_up = QChar(0xf028);
        const QString fa_vote_yea = QChar(0xf772);
        const QString fa_vr_cardboard = QChar(0xf729);
        const QString fa_vuejs = QChar(0xf41f);
        const QString fa_walking = QChar(0xf554);
        const QString fa_wallet = QChar(0xf555);
        const QString fa_warehouse = QChar(0xf494);
        const QString fa_water = QChar(0xf773);
        const QString fa_wave_square = QChar(0xf83e);
        const QString fa_waze = QChar(0xf83f);
        const QString fa_weebly = QChar(0xf5cc);
        const QString fa_weibo = QChar(0xf18a);
        const QString fa_weight = QChar(0xf496);
        const QString fa_weight_hanging = QChar(0xf5cd);
        const QString fa_weixin = QChar(0xf1d7);
        const QString fa_whatsapp = QChar(0xf232);
        const QString fa_whatsapp_square = QChar(0xf40c);
        const QString fa_wheelchair = QChar(0xf193);
        const QString fa_whmcs = QChar(0xf40d);
        const QString fa_wifi = QChar(0xf1eb);
        const QString fa_wikipedia_w = QChar(0xf266);
        const QString fa_wind = QChar(0xf72e);
        const QString fa_window_close = QChar(0xf410);
        const QString fa_window_maximize = QChar(0xf2d0);
        const QString fa_window_minimize = QChar(0xf2d1);
        const QString fa_window_restore = QChar(0xf2d2);
        const QString fa_windows = QChar(0xf17a);
        const QString fa_wine_bottle = QChar(0xf72f);
        const QString fa_wine_glass = QChar(0xf4e3);
        const QString fa_wine_glass_alt = QChar(0xf5ce);
        const QString fa_wix = QChar(0xf5cf);
        const QString fa_wizards_of_the_coast = QChar(0xf730);
        const QString fa_wolf_pack_battalion = QChar(0xf514);
        const QString fa_won_sign = QChar(0xf159);
        const QString fa_wordpress = QChar(0xf19a);
        const QString fa_wordpress_simple = QChar(0xf411);
        const QString fa_wpbeginner = QChar(0xf297);
        const QString fa_wpexplorer = QChar(0xf2de);
        const QString fa_wpforms = QChar(0xf298);
        const QString fa_wpressr = QChar(0xf3e4);
        const QString fa_wrench = QChar(0xf0ad);
        const QString fa_x_ray = QChar(0xf497);
        const QString fa_xbox = QChar(0xf412);
        const QString fa_xing = QChar(0xf168);
        const QString fa_xing_square = QChar(0xf169);
        const QString fa_y_combinator = QChar(0xf23b);
        const QString fa_yahoo = QChar(0xf19e);
        const QString fa_yammer = QChar(0xf840);
        const QString fa_yandex = QChar(0xf413);
        const QString fa_yandex_international = QChar(0xf414);
        const QString fa_yarn = QChar(0xf7e3);
        const QString fa_yelp = QChar(0xf1e9);
        const QString fa_yen_sign = QChar(0xf157);
        const QString fa_yin_yang = QChar(0xf6ad);
        const QString fa_yoast = QChar(0xf2b1);
        const QString fa_youtube = QChar(0xf167);
        const QString fa_youtube_square = QChar(0xf431);
        const QString fa_zhihu = QChar(0xf63f);
    };

}
#endif // FONTAWESOME_H
